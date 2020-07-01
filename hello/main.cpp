#include <iostream>
#include <string>
#include<iomanip>
#include<math.h>
using namespace std;
//ע�Ϳ�ݼ�ctrl+shift+c�����ע��ctrl+shift+x

//�ַ�����1
void print(char c){
    int base;
    //�жϴ�Сд
    if(c>=65&&c<=90){
        if(c<=90)base=65;
        else if(c>=97&&c<=122)base=97;
        else cout<<"���Ϸ����"<<endl;
    }else{
        cout<<"���Ϸ����"<<endl;
    }
    int num=c-base;
    int temp;
    for(int i=num;i>=0;i--){//ÿ��
        temp=num;//����
        while(temp>i){//����ո�
            temp--;
            cout<<" ";
        }
        for(int j=0;j<=i;j++){//�������
            cout<<(char)(base+j);
        }
        for(int j=i-1;j>=0;j--){//�������
            cout<<(char)(base+j);
        }
        cout<<endl;//����
    }
}

//�ַ�����2���е����⣬+32����3λ�����ϣ�
class MyString
{
    public:
        string newStr;
        int length;
};
MyString compress(string str){
    //ѹ��������ַ���
    MyString newStr;
    int length=str.size();
    string sub;
    int j;
    for(int i=0;i<length;i+=2){
        if(i<length-1){
            sub=str.substr(i,2);
        }else{
            //���һ��
            sub=str.substr(i,1)+'0';
        }
        newStr.newStr=newStr.newStr+to_string(stoi(sub,0,10)+32);//��0λ�ÿ�ʼ��Ϊ10�������֣�������32
        newStr.length=length;
    }
    cout<<"ѹ���ɹ�"<<endl;
    return newStr;
}
string uncompress(MyString newStr){
    string str,sub;
    if(newStr.length%2==0){
        //���Ϊż��
        for(int i=0;i<newStr.length;i+=2){
            sub=newStr.newStr.substr(i,2);
            str=str+to_string(stoi(sub,0,10)-32);
        }
    }else{
        //���Ϊ����
        for(int i=0;i<newStr.length-1;i+=2){
            sub=newStr.newStr.substr(i,2);
            str=str+to_string(stoi(sub,0,10)-32);
        }
        sub=newStr.newStr.substr(newStr.length-1,2);
        cout<<sub;
        str=str+to_string(stoi(sub,0,10)-32).substr(0,1);//��������
    }

    cout<<"��ѹ���ɹ�"<<endl;
    return str;
}

//���������3
float findAverage(float scores[]){
    int max_num=0,min_num=0;
    int i;
    float sum;
    for(i=1;i<=6;i++){
        //�и���ֵ
        if(scores[i]>scores[max_num]){
            max_num=i;
        }
        //�и�Сֵ
        if(scores[i]<scores[min_num]){
            min_num=i;
        }
    }
    for(i=0;i<=6;i++){
        if(i!=min_num&&i!=max_num){
            sum+=scores[i];
        }
    }
    return sum/5;
}

//�ַ�����4
string deleteBlank(string str){
    //������ͷ�ո�
    int i=0;
    while(i<str.size()&&isspace(str[i])){
        i++;
    }//iָ���һ���ǿ��ַ�
    return str.substr(i);
}
string mergeBlank(string str){
    //�м����ո�ֻ����һ��
    int flag=0,i;//ǰ���Ƿ��пո�
    string new_str;
    for(i=0;i<str.size();i++){
        if(isspace(str[i])&&flag==0){//��һ���ո�
            flag=1;
            new_str+=str[i];
        }else if(!isspace(str[i])){//�ǿո�
            new_str+=str[i];
            if(flag==1)flag=0;
        }
    }
    return new_str;
}
string separate(string str){
    //������ĸ�����_
    int flag=2,i;//ǰ������ĸΪ1������Ϊ0���ո�Ϊ2
    for(i=0;i<str.size();i++){
        if(!isspace(str[i])&&flag==2){
            //��һ���ǿ��ַ�
            if(isalpha(str[i]))flag=1;
            else if(isdigit(str[i]))flag=0;
        }
        if(isalpha(str[i])&&flag==0){
            flag=1;
            str.insert(i,"_");//�ڴ��ַ�ǰ����
        }else if(isdigit(str[i])&&flag==1){
            flag=0;
            str.insert(i,"_");
        }
    }
    return str;
}

//��׼c��5
void getPrime1(int n){//�õ�ȫ����С��n��������ɸѡ��
    bool* b = new bool[n+1];
    for(int i=2;i<=n;i++){//��2��ʼ����ɸѡ
        if(!b[i]){
            printf("%d\n",i);//�������
            for(int j=i+i;j<=n;j+=i){
                //Ϊtrue��ɸѡ��
                b[j] = true;
            }
        }
    }
}
void getPrime2(int n){//�õ�ȫ����С��n�����������㣩
    int j;
    for(int i=2;i<=n;i++){
        for(j=2;j<=sqrt(i);j++){
            if(i%j==0)break;
        }
        if(j>sqrt(i))printf("%d\n",i);
    }
}
void twinPrime(int m){//��������������m�������������
    //�����õ�һ���������ҵ�2~m�������������Ӻ���ǰ�ж�
}

//��׼c��6
void printMatrix(int n){//nά�����˳ת����
    //����
    int **matrix=(int **)malloc(sizeof(int)*n);
    for(int i=0;i<n;i++){
        matrix[i]=(int *)malloc(sizeof(int)*n);
    }
    int *r=(int *)malloc(sizeof(int)*n);//ÿ���Ѷ�Ԫ����
    int *c=(int *)malloc(sizeof(int)*n);//ÿ���Ѷ�Ԫ����
    for(int i=0;i<n;i++){//��ʼ��
        r[i]=0;
        c[i]=0;
    }

    int x=0,y=-1;
    int flag=0;//��ʾ��һ�����ֵ���д���򡪡�0/1/2/3
    for(int j=1;j<pow(n,2)+1;j++){
        //���ݷ���ı�λ�ã���������
        if(j==25)printf("%f\n",pow(n,2));//������
        switch(flag){
            case 0:y++;break;
            case 1:x++;break;
            case 2:y--;break;
            case 3:x--;break;
            default:printf("����");
        }
        matrix[x][y]=j;
        //�޸�
        r[x]++;
        c[y]++;
        if(flag==0&&r[x]>=n){
            //��������
            flag=1;
        }else if(flag==1&&c[y]>=n){
            flag=2;
        }else if(flag==2&&r[x]>=n){
            flag=3;
        }else if(flag==3&&c[y]>=n){
            flag=0;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            printf("%d ",matrix[i][j]);
        printf("\n");
    }
    //�ͷ�
    free(r);
    free(c);
    for(int i=0;i<n;i++)
        free(matrix[i]);
    free(matrix);
}



int main()
{
//����1
//    cout<<"�������ַ���"<<endl;
//    char c;
//    cin>>c;
//    print(c);

//����2
//    string str1,str2;
//    do{
//       cout<<"�������ַ���"<<endl;
//       cin>>str1;
//    }while(str1.empty());//���Ϊ�ջ�ȫΪ���֣�������ȡ
//
//    MyString newStr=compress(str1);
//    cout<<"��ѹ��Ϊ��"<<newStr.newStr<<endl;
//    str2=uncompress(newStr);
//    cout<<"��ѹ��ԭ��Ϊ��"<<str2<<endl;

//����3
//    cout<<"��������λ��ί���֣�"<<endl;
//    float scores[7];
//    for(int i=0;i<7;i++){
//        cin>>scores[i];
//    }
//    float average_score=findAverage(scores);
//    cout<<fixed<<setprecision(1)<<"ƽ����Ϊ��"<<average_score<<endl;

//����4
//    string str,new_str;
//    cout<<"������һ���ַ���"<<endl;
//    getline(cin,str);//��Ϊ������ַ������ո�Ҫ�����ַ�������
//    new_str=separate(str);
//    cout<<"������Ϊ��"<<new_str<<endl;

//����5
//    getPrime1(400);

//����6
//    printMatrix(5);

//����7
}

