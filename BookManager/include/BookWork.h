#ifndef BOOKWORK_H
#define BOOKWORK_H

#include <string>
#include <Book.h>

using namespace std;

//ҵ����

class BookWork
{
    public:
        BookWork();         //�޲ι��캯��

        void initialBook(int=0);   //��ʼ��ͼ��
        void queryAllBook();        //��ʾ����ͼ��
        void queryBookByString(const string&); //����ͼ��
        int tellBookPosition(const string&);   //��λͼ���¼
        bool insertBook(Book);                  //����ͼ��
        bool updateBook(Book,int);              //����ͼ�飺���µ�n����¼
        bool deleteBook(int);                   //ɾ��ͼ�飺ɾ����n����¼
};

#endif // BOOKWORK_H
