#ifdef c
#define
class Debug
{   pubilc:
    constexpr Debug(bool b==true): hw(b),io(b),other(b) {}
    constexpr Debug(bool h,bool i,bool o):
    hw(h),io(i),other(o) {}
    constexpr bool any() {return hw||io||other;}
    void set_io(bool b) {io=b;}
    void set_hw(bool b) {hw=b;}
    void set_other (bool b){hw=b;}
    private:
    bool hw;
    bool io;
    bool other;
    
};

#endif