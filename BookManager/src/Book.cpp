#include <iostream>
#include <iomanip>
#include <cstring>
#include <Book.h>

//�޲ι���
Book::Book()
{
    strcpy(this->bookid,"");
    strcpy(this->bookname,"");
    strcpy(this->author,"");
    this->price = 0.00;
    strcpy(this->publish,"");
}
//�вι���
Book::Book(char bookid[],char bookname[],char author[],double price,char publish[])
{
    strcpy(this->bookid,bookid);
    strcpy(this->bookname,bookname);
    strcpy(this->author,author);
    this->price = price;
    strcpy(this->publish,publish);
}

//setter������ʵ��
void Book::setBookid(char bookid[])
{
    strcpy(this->bookid,bookid);
}
void Book::setBookname(char bookname[])
{
    strcpy(this->bookname,bookname);
}
void Book::setAuthor(char author[])
{
    strcpy(this->author,author);
}
void Book::setPrice(double price)
{
    this->price = price;
}
void Book::setPublish(char publish[])
{
    strcpy(this->publish,publish);
}
//getter������ʵ��
char* Book::getBookid()
{
    return bookid;
}
char* Book::getBookname()
{
    return bookname;
}
char* Book::getAuthor()
{
    return author;
}
double Book::getPrice()
{
    return price;
}
char* Book::getPublish()
{
    return publish;
}

//������Ա����
//���һ��ͼ���¼
void Book::showBook()
{
    cout<<setw(10)<<left<<bookid<<setw(30)<<left<<bookname;
    cout<<setw(20)<<left<<author<<setw(10)<<left<<price;
    cout<<setw(20)<<left<<publish<<endl;
}

//ȡ��һ��ͼ�����Ϣ�ַ���
string Book::getBookString()
{
    //������Ϣ�ַ���
    char bookString[200] = "";
    //������Ϣ�ַ���
    strcpy(bookString,bookid);
    strcat(bookString,bookname);
    strcat(bookString,author);
    strcat(bookString,publish);
    //������Ϣ�ַ���
    return string(bookString);
}

Book::~Book()
{
    //dtor
}
