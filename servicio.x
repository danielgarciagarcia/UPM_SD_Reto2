struct get_guid_reply {
    int guid;
    int uids<>;
};

struct gname_linked_list {
    string gname<>;
    struct gname_linked_list *next;
};

struct get_uname_reply_true {
    string uname<>;
    struct gname_linked_list *linked_list;
};

union get_uname_reply switch(bool exists){
	case FALSE: void;
	case TRUE: get_uname_reply_true *reply;
};

program RETO_SERVICIO {
    version RETO_VERSION {
        get_guid_reply GET_GUID(string gname)=1;
        get_uname_reply GET_UNAME(int uid)=2;
    }=1;
}=666666666;