#ifndef BOOK_H
#define BOOK_H

#include <string>
using namespace std;

class Book
{
    public:
        Book(); //�޲ι���
        Book(char[],char[],char[],double,char[]); //�вι���

        //setter��Ա����
        void setBookid(char[]);
        void setBookname(char[]);
        void setAuthor(char[]);
        void setPrice(double);
        void setPublish(char[]);
        //getter��Ա����
        char* getBookid();
        char* getBookname();
        char* getAuthor();
        double getPrice();
        char* getPublish();
        //������Ա����
        void showBook(); //���һ����¼
        string getBookString(); //ȡ��ͼ����Ϣ�ַ���

        //��������
        virtual ~Book();

    private:
        char bookid[50];   //ͼ����
        char bookname[50]; //ͼ������
        char author[50];   //ͼ������
        double price;      //ͼ��۸�
        char publish[50];  //����������
};

#endif // BOOK_H
