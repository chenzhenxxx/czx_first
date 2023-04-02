//一
// #include<iostream>
// const volatile int model=90;    //volatile 忽略优化  C++中的常量折叠：指const变量（即常量）值放在编译器的符号表中，计算时编译器直接从表中取值，省去了访问内存的时间，从而达到了优化。
// const volatile int v[]={1,2,3,4};  
// const int x=1; //cosnt的数必须赋初值 
// void ff(){
// 	int x;
// 	std::cout<<"please input  model you want to modify:"<<std::endl;
// 	std::cin>>x;
// 	*(int *)&model=x; //将const int 强转成int赋值 

// 	int a=v[2];
// 	*(int*)&(v[2])=++a;   //一样的道理 
// 	std::cout<<model<<" "<<v[2]<<std::endl;
// }
// int main(){
// 	ff();
	
// }

//二
// #include<iostream>
// using namespace std;
// void sqr_it(int *i); 
// int main()
// {
//    int x;
//    cout<<"please input a int :"<<endl;
//    cin>>x;
//    sqr_it(&x); 
//    cout<<"The squre of x is "<<x << '\n'; 
//    return 0;
// } 

// void sqr_it(int *i){
// 	*i=(*i)*(*i);
// }


//3
// #include<iostream>
// int max (int a,int b){
// 	return a>b?a:b;
// } 
// long  max (long a,long b){
// 	return a>b?a:b;
// } 
// double max (double a,double b){
// 	return a>b?a:b;
// } 
// int main(){
// 	std::cout<<"please input two int:"<<std::endl;
// 	int a, b;
// 	std::cin>>a>>b; 
// 	std::cout<<max(a,b)<<std::endl;
	
// 	std::cout<<"please input two long:"<<std::endl;
// 	long c, d;
// 	std::cin>>c>>d; 
// 	std::cout<<max(c,d)<<std::endl;
	
// 	std::cout<<"please input two double:"<<std::endl;
// 	double e, f;
// 	std::cin>>e>>f; 
// 	std::cout<<max(e,f)<<std::endl;
// }


//4
// #include<iostream>
// using namespace std;
// int main()
// {
// 	char * name=new char[20];
// 	cout<<"please input your name"<<endl;
// 	cin>> name;
// 	cout<<"hello "<<name <<endl;
// }


// #include <iostream>
// using namespace std;
//void f(int a[],int n,int *max, int * min){
//	*max=*min=a[0];
//	for(int i = 1 ; i < n ;i++){
//		if(*max < a[i]) * max = a[i];
//		if(*min > a[i]) * min = a[i];
//  	}
//}

// void f(int a[],int n,int &max, int &min){
// 	max=min=a[0];
// 	for(int i = 1 ; i < n ;i++){
// 		if(max < a[i]) max = a[i];
// 		if(min > a[i]) min = a[i];
//   	}
// }

// int main()
// {
// 	int a[10];
//    cout<<"please input 10 int :"<<endl;
//    for(int i=0;i<10;i++)
// {
// cin>>a[i];
// }
// 	int max,min;
// 	f(a,10,max,min);
// 	cout<<"Max : "<<max<<endl;
// 	cout<<"Min ；"<<min<<endl;
// 	return 0;
// }