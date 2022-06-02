#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <iomanip>
#include <BookWork.h>
#include <book.h>

//ҵ�������ľ���ʵ��

using namespace std;

//�޲ι��캯��
BookWork::BookWork()
{  }

//ҵ��1:��ʼ��ͼ������
void BookWork::initialBook(int n)
{
    //1����������ļ���
    ofstream fout("book.dat", ios_base::out|ios_base::binary);
    if(!fout.is_open())
    {
        cout<<"���ļ�ʧ�ܣ�"<<endl;
        fout.close();
        return;
    }

    //2������������¼��
    if(n!=0)
    {
        //2.1������ͼ�����
        Book book;

        //2.2������ͼ����Ϣ
        //�����һ��ͼ��
        book.setBookid((char*)"tu001");
        book.setBookname((char*)"C++�������������");
        book.setAuthor((char*)"�Ʊ���");
        book.setPrice(59);
        book.setPublish((char*)"�廪��ѧ������");
        fout.write((char*)(&book),sizeof(Book));  //�����һ����¼
        //����ڶ���ͼ��
        book.setBookid((char*)"tu002");
        book.setBookname((char*)"Java�������");
        book.setAuthor((char*)"��С��");
        book.setPrice(45.88);
        book.setPublish((char*)"�����ʵ������");
        fout.write((char*)(&book),sizeof(Book));  //����ڶ�����¼
        //���������ͼ��
        book.setBookid((char*)"tu003");
        book.setBookname((char*)"���ݿ�ϵͳԭ��");
        book.setAuthor((char*)"����ǿ");
        book.setPrice(35.55);
        book.setPublish((char*)"�廪��ѧ������");
        fout.write((char*)(&book),sizeof(Book));  //�����������¼
    }
    cout<<endl<<"�ļ���ʼ���ɹ�!"<<endl;

    //3���ر��ļ���
    fout.close();
}

//ҵ��2����ʾ���е�ͼ��
void BookWork::queryAllBook()
{
    //1:�����ͷ
    cout<<setw(10)<<left<<"ͼ����"<<setw(30)<<left<<"ͼ������";
    cout<<setw(20)<<left<<"ͼ������"<<setw(10)<<left<<"ͼ��۸�";
    cout<<setw(20)<<left<<"������"<<endl;

    //2:���������ļ�������
    ifstream fin("book.dat",ios_base::in|ios_base::binary);
    if(!fin.is_open())
    {
        cout<<"�ļ���ʧ�ܣ�"<<endl;
        fin.close();
        return;
    }

    //3:ѭ���������
    //3.1������Ϣ����
    Book book;   //����һ��ͼ�飨���ڱ�����ȡ�����ݣ�
    fin.seekg(0,ios_base::end);
    int bookSize = fin.tellg()/sizeof(Book); //��ͼ������
    fin.seekg(0,ios_base::beg); //�ļ�λ��ָ�븴λ

    //3.2�������
    for(int i=0;i<bookSize;i++)
    {
        fin.read((char*)&book,sizeof(Book)); //��ȡһ����¼
        book.showBook(); //���һ����¼
    }
    cout<<endl;

    //4:�ر��ļ�
    fin.close();
}

//ҵ��3������ͼ��
void BookWork::queryBookByString(const string& findStr)
{
    //1�������ͷ
    cout<<setw(10)<<left<<"ͼ����"<<setw(30)<<left<<"ͼ������";
    cout<<setw(20)<<left<<"ͼ������"<<setw(10)<<left<<"ͼ��۸�";
    cout<<setw(20)<<left<<"������"<<endl;

    //2�����������ļ�������
    ifstream fin("book.dat",ios_base::in|ios_base::binary);
    if(!fin.is_open())
    {
        cout<<"�ļ���ʧ�ܣ�"<<endl;
        fin.close();
        return;
    }

    //3������ͼ���¼��
    fin.seekg(0,ios_base::end); //�ļ�ָ��λ�ö�λ���ļ�β
    int bookSize = fin.tellg()/sizeof(Book); //����ͼ���¼����
    fin.seekg(0,ios_base::beg);              //�ļ�λ��ָ�븴λ

    //4��ѭ����������
    if(bookSize>0)
    {
        //�ļ������ݡ�������
        Book book;   //����һ��ͼ�飬���ڱ�����ȡ������
        string bookString = (char*)""; //ͼ��ļ�¼��Ϣ�ַ���
        std::size_t found;       //�ַ������ҵ�λ��
        bool foundFlag = false;  //���ұ�Ǳ���

        //ѭ������ÿ��ͼ���¼
        for(int i=0;i<bookSize;i++)
        {
            //��ȡ����
            fin.read((char*)&book,sizeof(Book)); //��ȡһ����¼
            bookString = book.getBookString();    //ȡ����Ϣ�ַ���

            //������Ϣ
            found = bookString.find(findStr);

            //�����ж�
            if(found!=string::npos)
            {
                book.showBook();  //���ͼ���¼
                foundFlag = true; //���ı�Ǳ���
            }
        }
        if(foundFlag==false) cout<<endl<<"���޴���!!!"<<endl;
        else cout<<endl;
    }
    else
    {
        //�ļ�û����
        cout<<endl<<"�ļ�û���ݣ����ܲ���ͼ�飡"<<endl;
    }

    //5���ر��ļ�
    fin.close();
}

//ҵ��4������ͼ��
bool BookWork::insertBook(Book book)
{
    //1����������ļ���
    ofstream fout;
    fout.open("book.dat",ios_base::app|ios_base::binary); //���ļ�����׷�ӷ�ʽ���ļ���
    if(!fout.is_open())
    {
        cout<<"���ļ�ʧ�ܣ�"<<endl;
        fout.close();
        return false;
    }

    //2��д�뱣�浽�ļ�
    fout.write((char*)&book,sizeof(Book)); //д���ļ�

    //3���ر��ļ�
    fout.close();
    return true;
}

//ҵ��5������ͼ��
bool BookWork::updateBook(Book book,int bookPos)
{
    //1����������ļ���
    fstream finout;  //����ʹ��ofstream������Ϊ�ö���򿪹����ļ�ʱ��������ļ�����
    finout.open("book.dat",ios_base::in|ios_base::out|ios_base::binary); //���ļ�(�ɶ����ļ�����
    if(!finout.is_open())
    {
        cout<<"���ļ�ʧ�ܣ�"<<endl;
        finout.close();
        return false;
    }

    //2����¼��λ����д��(�޸�)�ļ�
    finout.seekp(bookPos*sizeof(Book),ios_base::beg);  //�ļ�λ��ָ�붨λ��Ŀ���¼
    finout.write((char*)&book,sizeof(Book));      //д���ļ�

    //3���ر��ļ�
    finout.close();
    return true;
}

//ҵ��6��ɾ��ͼ��
bool BookWork::deleteBook(int bookPos)
{
    //1��������������ļ���
    ofstream fout;
    fout.open("booktemp.dat",ios_base::out|ios_base::binary); //booktemp.dat����ʱ�ļ�
    ifstream fin;
    fin.open("book.dat",ios_base::in|ios_base::binary); //���ļ�

    if(!fout.is_open() || !fin.is_open())
    {
        cout<<"���ļ�ʧ�ܣ�"<<endl;
        fout.close();
        fin.close();
        return false;
    }

    //2������ͼ���¼��
    fin.seekg(0,ios_base::end);
    int bookSize = fin.tellg()/sizeof(Book);  //ͼ������
    fin.seekg(0,ios_base::beg);    //�ļ�λ��ָ�븴λ

    //3����¼��λ��ɾ����¼
    Book book; //����ͼ�飬������ȡ������
    for(int i=0;i<bookSize;i++)
    {
        fin.read((char*)(&book),sizeof(Book)); //��ȡ��¼
        if(i==bookPos)
        {
            continue; //Ҫɾ���ļ�¼��������
        }
        else
        {
            fout.write((char*)(&book),sizeof(Book)); //д��¼
        }
    }

    //4���ر��ļ�
    fout.close();
    fin.close();

    //5������ʱ�ļ����������¸��Ƶ���ʽ�ļ�
    fout.open("book.dat",ios_base::out|ios_base::binary); //���ļ�
    fin.open("booktemp.dat",ios_base::in|ios_base::binary); //���ļ�
    for(int i=0;i<bookSize-1;i++)
    {
        fin.read((char*)(&book),sizeof(Book)); //��ȡ��¼
        fout.write((char*)(&book),sizeof(Book)); //д��¼
    }
    fout.close();
    fin.close();

    return true;
}

//ҵ��7��ͼ���¼��λ
 int BookWork::tellBookPosition(const string& mBookid)
 {
    //1:���������ļ���
    ifstream fin("book.dat",ios_base::in|ios_base::binary);
    if(!fin.is_open())
    {
        cout<<"�ļ���ʧ�ܣ�"<<endl;
        fin.close();
        return -1; //����ֵΪ����˵��ͼ�鲻����
     }

    //2:ͳ��ͼ���¼��
    fin.seekg(0,ios_base::end);  //�ļ�λ��ָ�붨λ���ļ�β
    int bookSize = fin.tellg()/sizeof(Book);  //����ͼ���¼����
    fin.seekg(0,ios_base::beg);  //�ļ�λ��ָ�븴λ

    //3:ѭ��������λ
    int bookPos = -1;   //ͼ���¼λ�ã�Ĭ��ֵΪ����ͼ�鲻���ڣ�
    Book book;          //����һ��ͼ�飬���ڱ�����ȡ������
    string bookString = (char*)""; //ͼ��ļ�¼��Ϣ�ַ���

    for(int i=0;i<bookSize;i++)
    {
        fin.read((char*)(&book),sizeof(Book)); //��ȡһ����¼
        bookString = (book.getBookString()).substr(0,5); //ͨ��ͼ���¼��Ϣ�ַ�����ȡ��ͼ����
        if(bookString.compare(mBookid)==0)
        {
            //�ҵ�
            bookPos = i; //����λ��
            break;       //��ֹѭ��
        }
     }

     //4:�ر��ļ�
     fin.close();
     return bookPos; //���ؼ�¼λ��
 }



