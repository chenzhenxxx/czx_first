#include<iostream>
using namespace std;
class Screen
{
    public :
    typedef std::string ::size_type pos;
    Screen()=default;
    Screen(pos ht,pos wd,char c): height(ht),wideth(wd),contents(ht*wd,' '){}
char get() const
   {return contents[cursor];}
    inline char get (pos ht,pos wd)const;
    Screen move(pos r,pos c);
    inline Screen set(char);
    inline Screen set(pos,pos,char);
    Screen display(ostream &os){do_display(os);return *this;}
    const Screen display(ostream &os)const {do_display(os);return *this;}
    
    private:
    pos cursor=0;
    pos height=0,wideth=0;
    std::string contents;
    void do_display(std::ostream &os)const {os<<contents;}
};
inline
Screen Screen ::move(pos r,pos c)
{
  pos row=r*wideth;
  cursor =row+c;
  return *this;
}
char Screen::get(pos r,pos c) const
{
    pos row=r*wideth;
    return contents[row+c];
}
Screen Screen::set(char c)
{
    contents[cursor]=c;
    return *this;
}
Screen Screen::set(pos r,pos col,char ch)
{
    contents[r*wideth+col]=ch;
    return *this;
}
int main()
{
    Screen myScreen(5,5,'X');
    myScreen.move(4,0).set('#').display(cout);
    cout<<"\n";
    myScreen.display(cout);
    cout<<"\n";
}

