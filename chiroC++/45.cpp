//C++复制与拷贝构造函数

//浅拷贝只是对指针的拷贝，拷贝后两个指针指向同一个内存空间
//深拷贝 深拷贝不但对指针进行拷贝，而且对指针指向的内容进行拷贝，经深拷贝后的指针是指向两个不同地址的指针。
#include <string>
#include <iostream>
#include <cstring>

class String
{
private:
     char* m_Buffer;
     unsigned int m_Size;
public:
     String(const char* string)
     {
         m_Size = strlen(string);
         m_Buffer = new char[m_Size+1];
         memcpy(m_Buffer, string, m_Size+1);
         m_Buffer[m_Size] = 0;
     }
     
     String(const String& other)
      : m_Size(other.m_Size)
      {
        m_Buffer = new  char[m_Size+1];
         memcpy(m_Buffer, other.m_Buffer+1, m_Size+1);
      }

     ~String()
     {
        delete[] m_Buffer;
     }
     char& operator[](unsigned int index)
     {
        return m_Buffer[index];
     }
     friend std::ostream& operator <<(std::ostream& stream, const String& string);
};

std::ostream& operator <<(std::ostream& stream, const String& string)
{
   stream << string.m_Buffer;
   return stream;
}

int main()
{
    String a="czx";
    String b = a;
    b[2] ='h';
    std::cout << a << std::endl;
}