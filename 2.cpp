 7-1 �������ѧ֮������
/*
#include<stdio.h>
#include<string.h>
char* Dashuxiangjia(char *a1,char *a2);//������� 
int panduanhuiwenshu(char *a);//�жϻ����� 
char* reverse(char *a);//�����ݷ�ת 
int main(){
	char a1[1000]={'\0'},*a2,a3[1001]={'\0'},*temp,result[2000]={'\0'};
	char s[4]="--->";
	int i,n=3,k,len,count;
	while(scanf("%s",a1)!=EOF){
		count=0;
		temp=a1;
		for(k=0;k<strlen(a1);k++){
			result[k]=a1[k];
		}
		while(panduanhuiwenshu(temp)!=1){
			a2=reverse(temp);
			temp=Dashuxiangjia(temp,a2);
			len=strlen(temp);
			for(i=0;i<4;i++,k++)
				result[k]=s[i];
			for(i=0;i<len;i++,k++)
				result[k]=temp[i];
			count++;
			strcpy(a3,temp);
			temp=a3;
		}
		printf("%d\n",count);
		printf("%s\n",result);
		memset(a1,'\0',sizeof(a1));
		memset(result,'\0',sizeof(result));
	}
	return 0;
} 
char* Dashuxiangjia(char *a1,char *a2){
	int len1=strlen(a1);
	int len2=strlen(a2);
	int len3=(len1>len2)?len1:len2;
	int b1[1000]={0},b2[1000]={0},c[1001]={0};
	static char t[1001]={'\0'};
	memset(t,'\0',sizeof(t));
	int i;
	for(i=0;i<len1;i++){
		b1[i]=a1[len1-i-1]-'0';
	}
	for(i=0;i<len2;i++){
		b2[i]=a2[len2-i-1]-'0';
	}
	for(i=0;i<=len3;i++){
		c[i]=b1[i]+b2[i]+c[i];
		c[i+1]=(int)c[i]/10;
		c[i]=(int)c[i]%10;
	}
	if(c[len3]==0){
		for(i=0;i<len3;i++){
			t[i]=c[len3-1-i]+'0';
		}	
	}else{
		for(i=0;i<len3+1;i++){
			t[i]=c[len3-i]+'0';
		}
	}
	return t;
}
 
int panduanhuiwenshu(char *a){
	int len=strlen(a),i,j;
	for(i=0,j=len-1;i<=j;i++,j--){
		if(a[i]!=a[j])
		break;
	}
	if(i<=j)
		return 0;
	else
		return 1;
}
char* reverse(char *a){
	int i,j;
	static char b[1000]={'\0'};
	memset(b,'\0',sizeof(b));
	int len=strlen(a);
	for(i=0,j=len-1;i<len;i++,j--){
		b[i]=a[j];
	}
	return b;
}
*/
7-2 ��������ѧ����
/*
#include<bits/stdc++.h>
#include<algorithm>
#include<cstring>
#include<iostream>
using namespace std;
inline long long read()
{
    long long x=0,f=1;
    char ch=getchar();
    while(ch>'9'||ch<'0')
    {
        if(ch=='-')
        f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9')
    {
        x=(x<<1)+(x<<3)+(ch^48);
        ch=getchar();
    }
    return x*f;
}
int main()
{
    int n,T,k,f[1005];
    T=read();
    for(int i=1;i<=T;i++)
    {
        memset(f,0,sizeof(f));
        n=read(),k=read();
        f[1]=k;
        for(int j=2;j<=1000;j++)
        {
            f[j]=f[j-1]+(j-1)*(1+j-1)/2;
        }
        printf("%d\n",f[n]);
    }
    return 0;
}
*/
7-3 ѧ������ص�ͳ������
/*
#include<iostream>
#include<stdio.h>
#include<string>
using namespace std;
 
//�洢ȥ���ĳ��к�ʱ��
typedef struct Work
{
	string site;
	int date = 0;
}work[100];
 
//�洢������
typedef struct
{
	string site;//ȥ������ͬ����
	char name;//˭���ø���
	int date = 0;//����ʱ��
}same[100];
 
class Person
{
public:
	work works;
};
 
//����֮ǰ�Ƿ���ȥ����siteһ���ĳ���
int Same(string site, work works, int n)
{
	for (int i = 1; i < n; i++)
	{
		if (!site.compare(works[i].site)) return i;//�����򷵻�����works[]�е��±�
	}
	return 0;
}
 
int main()
{
	Person z, w;//���������Ž��ں�������
	char name, c;//c���ڽ���','
	int i, index, date;
	string site;
	for (int x = 0; x < 2; x++)//ѭ�����ηֱ�������������
	{
		scanf("%c:", &name);//z:
		if (name == 'z')
		{
			i = 1;
			cin >> z.works[i].site;//bj
			cin >> z.works[i].date;//3
			i++;
			while (scanf("%c", &c) && c == ',')//���Ҫ������һ��ȥ�����е����ݣ���������','
			{
				cin >> site;//����
				cin >> date;//ʱ��
				if (index = Same(site, z.works, i))//���֮ǰȥ����ͬ�ĳ���
				{
					z.works[index].date += date;//����֮ǰʱ��Ļ������ۼ�
				}
				else//��������������±�����
				{
					z.works[i].site = site;
					z.works[i].date = date;
					i++;
				}
			}
		}
		if (name == 'w')
		{
			i = 1;
			cin >> w.works[i].site;
			cin >> w.works[i].date;
			i++;
			while (scanf("%c", &c) && c == ',')
			{
				cin >> site;
				cin >> date;
				if (index = Same(site, w.works, i))
				{
					w.works[index].date += date;
				}
				else
				{
					w.works[i].site = site;
					w.works[i].date = date;
					i++;
				}
			}
		}
	}
	same sames;
	int n = 1;//ͳ��ȥ����ͬ���еĸ�������ʼֵΪ1�������������㣩
	for (int i = 1; z.works[i].date; i++)
	{
		for (int j = 1; w.works[j].date; j++)
		{
			if (!z.works[i].site.compare(w.works[j].site))//�����ȥ����ͬ�ĳ���
			{
				sames[n].site = z.works[i].site;//��¼��ͬ�ĳ���
				if (z.works[i].date > w.works[j].date)//z����ʱ���w�������¼z������
				{
					sames[n].date = z.works[i].date;
					sames[n].name = 'z';
				}
				else
				{
					sames[n].date = w.works[j].date;
					sames[n].name = 'w';
				}
				n++;
			}
		}
	}
	if (n == 1)//û��ȥ����ͬ�ĳ���
	{
		cout << "none" << endl;
		return 0;
	}
	//�����е�����ĸ��С����ð������
	string stemp; char ntemp; int dtemp;
	for (int i = 1; i < n; i++)
	{
		for (int j = 1; j < n - i; j++)
		{
			if (sames[j].site.compare(sames[j + 1].site) == 1)
			{
				stemp = sames[j].site;
				ntemp = sames[j].name;
				dtemp = sames[j].date;
				sames[j].site = sames[j + 1].site;
				sames[j].name = sames[j + 1].name;
				sames[j].date = sames[j + 1].date;
				sames[j + 1].site = stemp;
				sames[j + 1].name = ntemp;
				sames[j + 1].date = dtemp;
			}
		}
	}
	//��������Ľ��
	cout << sames[1].name << ":" << sames[1].site << " " << sames[1].date;
	for (int i = 2; i < n; i++)
	{
		cout << ",";
		cout << sames[i].name << ":" << sames[i].site << " " << sames[i].date;
	}
	return 0;
}
*/
7-4 ������
/*#include<bits/stdc++.h>
#include<algorithm>
#include<cstring>
#include<iostream>
using namespace std;
inline long long read()
{
    long long x=0,f=1;
    char ch=getchar();
    while(ch>'9'||ch<'0')
    {
        if(ch=='-')
        f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9')
    {
        x=(x<<1)+(x<<3)+(ch^48);
        ch=getchar();
    }
    return x*f;
}
long long  gcd(long long a,long long b)
{
    int maxx,minx;
    if(a>b) maxx=a,minx=b;
    if(a<b) maxx=b,minx=a;
    if(maxx%minx==0) return minx;
    return gcd(minx,maxx%minx);
}
int main()
{
    int T,n,a,b,ans=0;
    T=read();
    for(register int i=1;i<=T;i++)
    {
        ans=0;
        n=read();
        for(register int j=1;j<=n;j++)
        {   
            a=read(),b=read();
            if(gcd(a,b)==1) ans++;
        }
        printf("%d\n",ans);
    }
    return 0;
}*/
7-5 ������������
/*#include <stdio.h>
int main()
{
    int k,c=0,d=0,max=0,min=1000000;
    int a[100001];
    scanf("%d",&k);
    for(int i=0;i<k;i++)
    {
        scanf("%d",&a[i]);
    }
    for(int i=0;i<k;i++){
        if(a[i]>max)
            max=a[i];
        if(a[i]<min)
            min=a[i];
    }
    for(int i=0;i<k;i++){
        if(a[i]==max)
            c++;
        if(a[i]==min)
            d++;
    }
    printf("%d %d\n",min,d);
    printf("%d %d",max,c);
}
*/
7-6 ˭���Ե�
/*#include <iostream>
#include <string>
#include <vector>
using namespace std;
struct Student {
    string nickname;
    string QQ;
    char gender;
    int level;
    string title;
};
int main() {
    int n, m;
    cin >> n >> m;

    vector<Student> students(n);
    for (int i = 0; i < n; i++) {
        cin >> students[i].nickname >> students[i].QQ >> students[i].gender >> students[i].level >> students[i].title;
    }

    for (int i = 0; i < m; i++) {
        string QQ;
        int type;
        cin >> QQ >> type;

        for (int j = 0; j < n; j++) {
            if (students[j].QQ == QQ) {
                switch (type) {
                    case 1:
                        cin >> students[j].nickname;
                        break;
                    case 2:
                        cin >> students[j].gender;
                        break;
                    case 3:
                        cin >> students[j].level;
                        break;
                    case 4:
                        cin >> students[j].title;
                        break;
                }
                break;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        cout<<"["<<i+1<<"]"<<":"<<students[i].nickname<<"-"<< students[i].QQ << "-" << students[i].gender << "-" << students[i].level << "-" << students[i].title << endl;
    }
    return 0;
}
*/
7-7 h0215.����������
/*
#include<bits/stdc++.h>
using namespace std;
struct xx{
int a,b;
}s[40005];
int cmp(xx x,xx y){
    if(x.b==y.b)return x.a<y.a;
    return x.b<y.b;
}
int main(){
    int n,c=0,j=0;
   cin>>n;
    for(int i=0;i<n;i++){
       cin>>s[i].a>>s[i].b;
        if(s[i].a>s[i].b)//����������������������������
            swap(s[i].a,s[i].b);
    }
    sort(s,s+n,cmp);
    c+=1;
    for(int i=1;i<n;i++){
        if(s[i].a>s[j].b){
            c++;
            j=i;
        }
    }
   cout<<n-c;
    return 0;
} */
