#include <iostream>
#include <iomanip>
#include <cstring>
#include <BookWork.h>

using namespace std;

//���Ʋ㣺���̿��ƺ����ľ���ʵ��

//ʵ��ҵ��1����ʼ������
void toInitialBook(int n)
{
    BookWork bw;      //����ҵ�����
    bw.initialBook(n); //����ҵ�񷽷���ʵ��ҵ��
}

//ʵ��ҵ��2����ʾ����ͼ��
void toQueryAllBook()
{
    BookWork bw; //����ҵ�����
    bw.queryAllBook(); //����ҵ�񷽷���ʵ��ҵ��
}

//ʵ��ҵ��3������ͼ��
void toQueryBookByString()
{
    string findStr = ""; //��Ϣ�ַ���
    cout<<"��������ҵ�ͼ����Ϣ��";
    cin>>findStr;  //����

    BookWork bw;  //����ҵ�����
    bw.queryBookByString(findStr); //����ҵ�񷽷���ʵ��ҵ��
}

//ʵ��ҵ��4������ͼ��
void toInsertBook()
{
    //1:�����ַ���
    string titleStr[5]={"ͼ���ţ�","ͼ�����ƣ�","ͼ�����ߣ�","ͼ��۸�","����������"}; //�ֶ���Ϣ
    string valueStr[5]={"","","","",""}; //�ֶ�ֵ
    char mBookid[50],mBookname[50],mAuthor[50],mPublish[50]; //�ֶα���
    double mPrice;

    //2:�����ֶ�ֵ
    cout<<"������ͼ�����Ϣ��"<<endl;
    for(int i=0;i<5;i++)
    {
        cout<<titleStr[i];
        cin>>setw(50)>>valueStr[i];
    }

    //3:�����ֶ�ֵ��������ֵ���浽�ֶα���
    strcpy(mBookid,valueStr[0].c_str());  //stringҪתchar*
    strcpy(mBookname,valueStr[1].c_str());
    strcpy(mAuthor,valueStr[2].c_str());
    strcpy(mPublish,valueStr[4].c_str());
    mPrice = atof(valueStr[3].c_str());   //stringתdouble

    //4:������ʵ��������
    Book book(mBookid,mBookname,mAuthor,mPrice,mPublish); //ʵ��������

    //5:����ҵ����󣬲�����ҵ�񷽷�
    BookWork bw;
    bool insertFlag = bw.insertBook(book);
    if (insertFlag==true)
        cout<<endl<<"����ͼ��ɹ�!"<<endl;
    else
        cout<<endl<<"����ͼ��ʧ��!"<<endl;
}

//ʵ��ҵ��5������ͼ��
void toUpdateBook()
{
    //1:����Ҫ�޸ĵ�ͼ����
    string findBookid = "";
    cout<<"������Ҫ�޸ĵ�ͼ���ţ�";
    cin>>findBookid;

    //2:��λͼ��
    BookWork bw;  //����ҵ�����
    int bookPos  = bw.tellBookPosition(findBookid); //����ҵ�񷽷���ʵ��ҵ��

    //3:�޸ļ�¼
    if(bookPos>=0)
    {
        //�ҵ���¼
        //3.1:����ͼ����Ϣ
        char mBookid[50],mBookname[50],mAuthor[50],mPublish[50]; //�ֶα���
        double mPrice;
        cout<<"�����µ�ͼ����Ϣ"<<endl;
        cout<<"ͼ���ţ�";
        cin>>setw(50)>>mBookid;
        cout<<"ͼ�����ƣ�";
        cin>>setw(50)>>mBookname;
        cout<<"ͼ�����ߣ�";
        cin>>setw(50)>>mAuthor;
        cout<<"ͼ��۸�";
        cin>>setw(50)>>mPrice;
        cout<<"����������";
        cin>>setw(50)>>mPublish;

        //3.2:������ʵ��������
        Book book(mBookid,mBookname,mAuthor,mPrice,mPublish); //ʵ��������

        //3.3:����ҵ�񷽷���ʵ���޸�
        bool updateFlag = bw.updateBook(book,bookPos);
        if(updateFlag==true)
        {
            cout<<endl<<"ͼ���޸ĳɹ���";
        }
        else
        {
            cout<<endl<<"ͼ���޸�ʧ��!";
        }
    }
    else
    {
        //û�ҵ���¼
        cout<<endl<<"ͼ�鲻���ڣ��޸�ʧ�ܣ�"<<endl;
    }
}

//ʵ��ҵ��6��ɾ��ͼ��
void toDeleteBook()
{
    //1:����Ҫɾ����ͼ����
    string findBookid = "";
    cout<<"������Ҫɾ����ͼ���ţ�";
    cin>>findBookid;

    //2:��λͼ��
    BookWork bw;  //����ҵ�����
    int bookPos  = bw.tellBookPosition(findBookid); //����ҵ�񷽷���ʵ��ҵ��

    //3:ɾ��ͼ��
    if(bookPos>=0)
    {
        //�ҵ���¼
        bool deleteFlag = bw.deleteBook(bookPos); //����ҵ�񷽷���ʵ��ҵ��
        if(deleteFlag==true)
        {
            cout<<endl<<"ͼ��ɾ���ɹ���"<<endl;
        }
        else
        {
            cout<<endl<<"ͼ��ɾ��ʧ�ܣ�"<<endl;
        }
    }
    else
    {
        //û�ҵ���¼
        cout<<endl<<"ͼ�鲻���ڣ�ɾ��ʧ�ܣ�"<<endl;
    }
}

//��ʾ���˵�
void toMainMenu()
{
    system("cls");   //�����Ļ
    cout<<endl;
    cout<<"**************************************"<<endl;
    cout<<"*        ��ӭʹ��ͼ�����ϵͳ        *"<<endl;
    cout<<"*             �汾��2021             *"<<endl;
    cout<<"**************************************"<<endl;
    cout<<endl;
    cout<<"      [1] ��ʾȫ��ͼ��"<<endl;
    cout<<"      [2] ����ͼ��"<<endl;
    cout<<"      [3] ����ͼ��"<<endl;
    cout<<"      [4] ����ͼ��"<<endl;
    cout<<"      [5] ɾ��ͼ��"<<endl;
    cout<<"      [6] ��ʼ��ȫ��ͼ��"<<endl;
    cout<<"      [7] ��ʼ������ͼ��"<<endl;
    cout<<"      [0] �˳�ϵͳ"<<endl;
    cout<<endl;
}



