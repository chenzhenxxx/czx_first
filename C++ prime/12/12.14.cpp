#ifdef a
#define a
void function()
{

    ...
    shared_ptr<connection> p(&c,end_connection);
    shared_ptr<connection> p(&c,[](connection * p){disconnect(*p)};);

    ...
}
voidend_connection(connection *p)
{
    disconnect(*p);
}

#endif
