#include <iostream>
#include <BookController.h>

using namespace std;

int main()
{

    char choice;
    while(choice!='0')
    {
        toMainMenu();//��ʾ���˵�
        cout<<"��ѡ��˵���";
        cin>>choice; //����ֵ
        cout<<endl;

        switch(choice)
        {
        case '1':
            toQueryAllBook(); break;      //��ʾȫ��ͼ��
        case '2':
            toQueryBookByString(); break;  //����ͼ��
        case '3':
            toInsertBook(); break;         //����ͼ��
        case '4':
            toUpdateBook(); break;         //����ͼ��
        case '5':
            toDeleteBook(); break;         //ɾ��ͼ��
        case '6':
            toInitialBook(); break;        //��ʼ��ȫ��ͼ��
        case '7':
            toInitialBook(1); break;       //��ʼ������ͼ��
        case '0':
            cout<<"ллʹ�ã�Bye-Bye!"<<endl; break; //�˳�ϵͳ
        default:
            cout<<"ѡ���������ѡ��..."<<endl;
        }
        system("pause");
    }
    cout<<endl;

    return 0;
}
