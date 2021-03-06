/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#ifndef _SERVICIO_H_RPCGEN
#define _SERVICIO_H_RPCGEN

#include <rpc/rpc.h>


#ifdef __cplusplus
extern "C" {
#endif


struct get_guid_reply {
    int guid;
    struct {
        u_int uids_len;
        int *uids_val;
    } uids;
};
typedef struct get_guid_reply get_guid_reply;

struct gname_linked_list {
    char *gname;
    struct gname_linked_list *next;
};
typedef struct gname_linked_list gname_linked_list;

struct get_uname_reply_true {
    char *uname;
    struct gname_linked_list *linked_list;
};
typedef struct get_uname_reply_true get_uname_reply_true;

struct get_uname_reply {
    bool_t exists;
    union {
        get_uname_reply_true *reply;
    } get_uname_reply_u;
};
typedef struct get_uname_reply get_uname_reply;

#define RETO_SERVICIO 666666666
#define RETO_VERSION 1

#if defined(__STDC__) || defined(__cplusplus)
#define GET_GUID 1

extern get_guid_reply *get_guid_1(char **, CLIENT *);

extern get_guid_reply *get_guid_1_svc(char **, struct svc_req *);

#define GET_UNAME 2

extern get_uname_reply *get_uname_1(int *, CLIENT *);

extern get_uname_reply *get_uname_1_svc(int *, struct svc_req *);

extern int reto_servicio_1_freeresult(SVCXPRT *, xdrproc_t, caddr_t);

#else /* K&R C */
#define GET_GUID 1
extern  get_guid_reply * get_guid_1();
extern  get_guid_reply * get_guid_1_svc();
#define GET_UNAME 2
extern  get_uname_reply * get_uname_1();
extern  get_uname_reply * get_uname_1_svc();
extern int reto_servicio_1_freeresult ();
#endif /* K&R C */

/* the xdr functions */

#if defined(__STDC__) || defined(__cplusplus)

extern bool_t xdr_get_guid_reply(XDR *, get_guid_reply *);

extern bool_t xdr_gname_linked_list(XDR *, gname_linked_list *);

extern bool_t xdr_get_uname_reply_true(XDR *, get_uname_reply_true *);

extern bool_t xdr_get_uname_reply(XDR *, get_uname_reply *);

#else /* K&R C */
extern bool_t xdr_get_guid_reply ();
extern bool_t xdr_gname_linked_list ();
extern bool_t xdr_get_uname_reply_true ();
extern bool_t xdr_get_uname_reply ();

#endif /* K&R C */

#ifdef __cplusplus
}
#endif

#endif /* !_SERVICIO_H_RPCGEN */
