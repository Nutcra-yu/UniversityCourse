#include<iostream>
#include<stdlib.h>
#include<time.h>
#define XX 12   //�����R 
using namespace std;

typedef int ElemType;
typedef struct 
{
	ElemType *queue;
	int front,rear,len;
	int maxsize;
}Queue;

void Init(Queue &Q,int i)            //���� 
{
	Q.maxsize=i;
	Q.queue=new ElemType[Q.maxsize];
	Q.front=Q.rear=0;
	Q.len=0;
}

void str(Queue &Q,ElemType x)
{
	if((Q.rear+1)%Q.maxsize==Q.front)
	{
		int k=sizeof(ElemType);
		Q.queue=(ElemType*)malloc(2*Q.maxsize*k);
		if(Q.rear!=Q.maxsize-1)
		{
			for(int i=0;i<Q.rear;i++)
			{
				Q.queue[i+Q.maxsize]=Q.queue[i];
			}
			Q.rear+=Q.maxsize;
		}
		Q.maxsize*=2;
	}
	Q.queue[Q.rear]=x;
	Q.rear=(Q.rear+1)%Q.maxsize;
	Q.len++;
}

void delet(Queue &Q)
{
	Q.front=(Q.front+1)%Q.maxsize;
	Q.len--;
}

int main()
{
	Queue Qchair; 
	Queue Qwait;
	Init(Qchair,10);Init(Qwait,10);     
	
	int n,t;
	cout<<"���������ݣ�"<<endl;
	cout<<"һ�������Σ�";
	cin>>n;
	cout<<"��Ӫҵʱ��Ϊ��";
	cin>>t;
	
	srand((int)time(0));
	int h[999]; 
	int g[999]; 
	int x[999][2]; 
	int i=1;
	g[1]=0;  //��һ���˿� 
	int R;
	
	while(g[i]<60*t)   //���һ���˿� 
	{
		R=rand()%XX+1; 
		h[i]=15+R%50; 
		g[i+1]=g[i]+2+R%10;
		i++;
	}
	int a(1),b(1),c(1);
	for(i=0;i<60*t;i++) 
	{
		if(i==g[a])   //�˿��Ŷ� 
		{
			str(Qwait,i);
			a++;
		}
		if(Qchair.len>0&&(i-Qchair.queue[Qchair.front])>=h[c])    //����ɣ�ɾ������ 
		{ 
			delet(Qchair);
			c++;
		}
		if(Qchair.len<n&&Qwait.len>0) 
		{
			delet(Qwait); 
			str(Qchair,i); 
			x[b][1]=Qwait.len; 
			x[b++][0]=i; 
		}
	}
	for(;;i++)   //��β 
	{
		if(Qchair.len>0&&(i-Qchair.queue[Qchair.front])>=h[c]) 
		{
			delet(Qchair);
			c++;
		}
		if(Qchair.len<n&&Qwait.len!=0)
		{
			delet(Qwait); 
			str(Qchair,i); 
			x[b][1]=Qwait.len; 
			x[b++][0]=i;
		}
		if(Qchair.len==0&&Qwait.len==0) 
		break;
	}
	int m(0);
	double l(0);
	double k(0);
	for(i=1;i<a;i++)
	{
		k+=x[i][0]-g[i]+h[i];   //����ʱ�� 
		l+=x[i][1];
	}
	k=k/(a-1);
	l=l/(a-1);
	m=x[a-1][0]+h[a-1]-60*t;
	cout<<"�˿͵�ƽ������ʱ��Ϊ:"<<k<<endl;
	cout<<" �Ŷ�ʱƽ���ӳ�Ϊ:"<<l<<endl;
	cout<<" ���ź���βʱ��Ϊ:"<<m<<endl;
	
	return 0;
}
