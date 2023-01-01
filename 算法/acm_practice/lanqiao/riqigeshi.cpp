#include<bits/stdc++.h>
#include<map>
using namespace std;
map<int,string> day;
int main()
{
    day[1]="Jan";
    day[2]="Feb";
    day[3]="Mar";
    day[4]="Apr";
    day[5]="May";
    day[6]="Jun";
    day[7]="Jul";
    day[8]="Aug";
    day[9]="Sep";
    day[10]="Oct";
    day[11]="Nov";
    day[12]="Dec";

    int month,d;
    scanf("%d %d",&month,&d);
    cout<<day[month]<<endl;
    printf("%02d",d);


}