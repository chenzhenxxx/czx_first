#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<windows.h>
#define M 100 
using namespace std;
int isCSH = 0;//是否初始化（否）
int isMN = 0; // 是否模拟 

class Windows {
	public:
		int queue[M];  // 队列 
		int front = -1 ;
		int rear = -1 ;
		int traffic = 0; // 接待顾客量 
		int line = 0; // 正在排队人数 
		int num; //窗口号 
		static double total_time;//所用人在银行总用时 
		
		void init_windows(){  // 函数： 初始化队列全设为 0, 0代表没有人，其他数字代表用时 
			for(int i=0;i<M;i++)
				queue[i] = 0;
		}
		int EMPTYQ(){
			return front == rear ;
		}
		int ADDQ(int item){
			if(rear == M-1)
				return 0; //失败
			else {
				queue[++rear] = item;
				traffic++ ; 
				line++; 
				return 1; // 成功 
			} 
		}
		int DELQ(){
			if(EMPTYQ())
				return 0;
			else {
				front++;
				line--;
				return 1;
			}
		}
		void show_queue(){
			printf("窗口%d：",num); 
			for(int i=front+1;i<=rear;i++)
				printf("%4d",queue[i]);
			printf("\n");
		}
		void go_time(int interval){ //  interval表示时间间隔   --------------------改动1！！！ 
//			queue[front+1]--;   
			queue[front+1]-= interval; 
			if(queue[front+1]<0)
				queue[front+2] += queue[front+1];
				
			if(queue[front+1]<=0)
				DELQ();
			
		}	
		int QueuingTime(){
			int queueingtime = 0;
			for(int i=front+1;i<=rear;i++)
				queueingtime += queue[i];
			return queueingtime; 
		}
};
double Windows::total_time = 0; 
int findMin(Windows w[]){ // 函数：  返回排队人数最少的窗口的序号 
	if(w[0].line<w[1].line){
		if(w[0].line<w[2].line){
			if(w[0].line <w[3].line)
				return w[0].num;
			else return w[3].num;
		}
		else{
			 if(w[2].line <w[3].line )
			 	return w[2].num;
			else return w[3].num;
		}
	}
	else{ //w1>w2
		if(w[1].line <w[2].line ){
			if(w[1].line <w[3].line )
				return w[1].num;
			else return w[3].num;
		}
		else {
			if(w[2].line <w[3].line )
				return w[2].num;
			else return w[3].num;
		}
	}
}
int getMaxLine(Windows w[]){ //函数： 返回排队最多的队伍的人数 
	int max = 0; //最多排队人数 
	for(int i=0;i<4;i++){
		if(w[i].line>max)
			max = w[i].line;
	}
	return max;
} 
bool setProbability(double n){  //函数： 设置每interval分钟有客户进入的概率 
	int a[100];
	int N = n*100;
	for(int i = 0;i<N;i++)
		a[i] = 1;
	for(int i = N;i<100;i++)
		a[i] = 0;
	srand((unsigned)time(NULL));
	int sj = rand()%100;
	if(a[sj] == 1)
		return true;
	else return false;
	
} 
void menu(){	
	system("Cls"); 
	 cout<<"############银行模拟系统正在运行！#####################"<<endl;
	 cout<<"## tips: 为了简便，本程序将现实中的时间极大的缩短了  ##"<<endl; 
	 cout<<"##                                                   ##"<<endl;
	 cout<<"##"<<"       1.初始化(设置参数)"<<"                          ##"<<endl;
	 cout<<"##"<<"       2.开始模拟"<<"                                  ##"<<endl;
	 cout<<"##"<<"       3.查询本次模拟数据"<<"                          ##"<<endl;
	 cout<<"##"<<"       0.退出"<<"                                      ##"<<endl;
	 cout<<"##                                                   ##"<<endl;
	 cout<<"#######################################################"<<endl; 
	 cout<<"请选择>> ";
} 
void startBusiness(Windows w[], double openTime,int before,int after, double& afterTime,int interval,double probability){ // 函数： 开始营业 ~~ 
	//比率转换 程序1s == 现实10min ,workTime,afterTime以h为单位，before和after以min为单位 
	int WorkTime = 60* openTime; //比如，  480min ==60*8h  
	int AfterTime = 0;
	int shifouxianshi=0; // 代表没有显示过 "===== 银行开放时间结束，停止接收新客! ====="
	while(true){  
		Sleep(1000);
//		system("pause");
		AfterTime += interval; //程序1s == 现实10min 
		
		for(int i=0;i<4;i++)
			w[i].go_time(interval); // 每个窗口第一个人剩余用时开始减少 interval 分钟 
		
		srand((unsigned)time(NULL));
		if(AfterTime == 0 || AfterTime<=WorkTime && setProbability(probability) ){ //if里面是控制来新客人  在银行开放时间内，且每秒约80%的概率有顾客来(第一秒必来)
			int witeTime = (rand() % (after-before))+ before ;
			int minWinNum = findMin(w);
			w[minWinNum-1].ADDQ(witeTime); // 比如，随机在[15,60] ，代表需要 15-60min 办理业务;
			Windows::total_time += w[minWinNum-1].QueuingTime();	// 计算所有人在银行的总逗留时间 
//			cout<<"Windows::total_time = "<<Windows::total_time<<endl; 
		}
		
		cout<<"***营业"<<AfterTime<<"min时"<<endl; 
		cout<<"---------------------------------------------------"<<endl;
		for(int i=0;i<4;i++)
			w[i].show_queue();
		cout<<"---------------------------------------------------"<<endl;
			
		if(AfterTime>=WorkTime && shifouxianshi ==0){
			cout<<"===== 银行开放时间结束，停止接收新客! ====="<<endl;
			shifouxianshi = 1;
		}
		
		//退出循环条件 
		if(AfterTime>=WorkTime && getMaxLine(w) <=0)
			break; 
		
	}
	afterTime = AfterTime /60.0; //实际历时多少h 
}
int main(){
	Windows w[4];// 分别代表 1号，2号，3号，4号  窗口
	for(int i=0;i<4;i++){ //初始化每个窗口队列 
		w[i].init_windows();
		w[i].num = i+1;
	}
	int before,after;//业务办理所用时间区间 min ；
	int interval; // 比率,程序1s等于现实interval 分钟 
	double openTime; // 银行预设营业时间 h 
	double afterTime;//银行实际营业时间 h
	double probability;//每interval min有客户进入的概率，用小数表示 
	
//	cout<<"!!!!!!!!!#"<<w[0].num<<"#!!!!!!!!"<<endl; 
	while(true){
		menu();
		int select;
		cin>>select;
		switch(select){
			case 1: { //初始化(设置参数)
				isCSH = 1;
				system("Cls");
				cout<<"* 请设置业务办理所需时间(min)区间（例：15 60）: ";
				cin>>before>>after;
				if(before>after||before<=0){ // 判断数据正确性 
					isCSH = 0;
					cout<<"error! 数据输入不合理"<<endl;
					system("pause");
					break;
				}
				cout<<"* 请设置银行营业时间(h)（例：8）：";
				cin>>openTime;
				if(openTime>24||openTime<0){// 判断数据正确性 
					isCSH = 0;
					cout<<"error! 必须在[0,24]之间"<<endl;
					system("pause");
					break;
				}
				cout<<"* 请设置时间比率 （例：10,表示程序1s等于程序10分钟）: ";
				cin>>interval;
				if(interval<1){
					isCSH = 0;
					cout<<"error! 必须在大于1"<<endl;
					system("pause");
					break;
				} 
				cout<<"* 请设置现实每"<<interval<<"min有客户进入的概率(例: 0.8)：";
				cin>>probability;
				if(probability<0 || probability>1){
					isCSH = 0;
					cout<<"error! 必须在(0,1)之间"<<endl;
					system("pause");
					break;
				}
				 
				break;
			}
			case 2:{ //开始模拟
				system("Cls");
				if(isCSH){
					isMN = 1;
					cout<<"//程序运行1s 模拟银行营业 "<<interval<<"min"<<endl
						<<"//数字代表每个客户办理业务所剩时间（为方便观看，以min为单位）"<<endl
						<<"//为了快速获得模拟结果，可以注释Sleep(1000); 解开system(\"pause\"); （位于121行）"<<endl;
					startBusiness(w,openTime,before,after,afterTime,interval,probability); 
					cout<<"@模拟结束！"<<endl;
				}
				else cout<<"请先初始化"<<endl;
				system("pause");
				break;
				
			}
			case 3:{ // 查询本次模拟数据 
				system("Cls");
				if(isCSH && isMN){
					cout<<"---------------------------------------------------"<<endl;
					cout<<"本次银行预设营业"<<openTime<<"h, 实际营业"<<afterTime<<"h"<<endl
						<<"每位客户在银行平均逗留时间"<< Windows::total_time*1.0/(w[0].traffic+w[1].traffic+w[2].traffic+w[3].traffic)<<"min"<<endl
						<<"窗口1接待客户"<<w[0].traffic<<"名"<<endl
						<<"窗口2接待客户"<<w[1].traffic<<"名"<<endl
						<<"窗口3接待客户"<<w[2].traffic<<"名"<<endl
						<<"窗口4接待客户"<<w[3].traffic<<"名"<<endl;
					cout<<"---------------------------------------------------"<<endl;
				}
				else if(isCSH && !isMN) cout<<"请先模拟"<<endl;
				else if(!isCSH) cout<<"请先初始化"<<endl;
				system("pause");
				break;
			}
			case 0:{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN); 
				cout<<"感谢使用！再见！"<<endl;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY);
				return 0;
			}
			default: {
				cout<<"error！请重新选择 "<<endl; 
				system("pause");
				break;
			}
		}
		
	}
}

