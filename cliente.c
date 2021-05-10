/*
 * This is the client code.
 * Its structure (definition of the functions) has been automatically generated by the rpcgen tool based on the RPC
 * definitions located in the file "servicio.x". The implementation of the functions have been developed by myself.
 */

#include "servicio.h"

/*
 * This client receives as arguments the server's address and a list of Linux group names. It uses RPC to request to
 * the server the translation of those group names into GID and collect the users (username and UID) who are members of
 * that group. This information is extracted from the server's /etc/group and /etc/passwd files and printed locally.
 */
int main(int argc, char *argv[]) {
    char *host;
    if (argc < 3) {
        printf("usage: %s server_host group_names\n", argv[0]);
        return EXIT_FAILURE;
    }
    host = argv[1];

    CLIENT *clnt;
    get_guid_reply *groupInfo;
    get_uname_reply *userInfo;

    clnt = clnt_create(host, RETO_SERVICIO, RETO_VERSION, "tcp");
    if (clnt == NULL) {
        clnt_pcreateerror(host);
        return EXIT_FAILURE;
    }

    for (int i = 2; i < argc; ++i) {
        groupInfo = get_guid_1(&argv[i], clnt);
        if (groupInfo == (get_guid_reply *) NULL) {
            clnt_perror(clnt, "first call failed");
        } else if (groupInfo->guid == -1) {
            printf("%s%s%s\n", "The group ", argv[i], " does not exist.\n");
        } else {
            printf("gname: %s\nGID: %d\n", argv[i], groupInfo->guid);
            for (int j = 0; j < groupInfo->uids.uids_len; ++j) {
                userInfo = get_uname_1(&groupInfo->uids.uids_val[j], clnt);
                if (userInfo == (get_uname_reply *) NULL) {
                    clnt_perror(clnt, "second call failed");
                } else {
                    printf("member %d:\n    username: %s\n    UID: %d\n",
                           j,
                           userInfo->get_uname_reply_u.reply->uname,
                           groupInfo->uids.uids_val[j]);
                }
            }
            printf("\n");
        }
    }

    clnt_destroy (clnt);

    return EXIT_SUCCESS;
}
