#include<iostream>
#include<string>
#include<cmath>
#include<iomanip>
using namespace std;

struct student
{
    string name;
    int grade[20];
    double sum;
    int rank;
};

struct ranking
{
    double s;
    int r;
};

double gradepoint(int grade)
{
    if(grade>=90&&grade<=100)
    {
        return 4.0;
    }
    else if(grade>=86&&grade<=89)
    {
        return 3.7;
    }
    else if(grade>=83&&grade<=85)
    {
        return 3.3;
    }
    else if(grade>=80&&grade<=82)
    {
        return 3.0;
    }
    else if(grade>=76&&grade<=79)
    {
        return 2.7;
    }
    else if(grade>=73&&grade<=75)
    {
        return 2.3;
    }
    else if(grade>=70&&grade<=72)
    {
        return 2.0;
    }
    else if(grade>=66&&grade<=69)
    {
        return 1.7;
    }
    else if(grade>=63&&grade<=65)
    {
        return 1.3;
    }
    else if(grade>=60&&grade<=62)
    {
        return 1.0;
    }
    else 
    {
        return 0;
    }
}


int main()
{
    int n,m;
    cin>>n>>m;
    int score[20];
    for(int i=0;i<m;i++)
    {
        cin>>score[i];
    }
    student stu[1100];
    ranking ran[1100];
    int k=0;
    for(int i=0;i<n;i++)
    {
        cin>>stu[i].name;
        stu[i].sum=0;
        for(int j=0;j<m;j++)
        {
            cin>>stu[i].grade[j];
            stu[i].sum+=(gradepoint(stu[i].grade[j])*score[j]);
        }
        stu[i].sum=round(stu[i].sum*10);
        stu[i].sum/=10;
        ran[k].s=stu[i].sum;
        k++;
        
        //这里其实可以填入的时候就排序，类似插入排序的感觉
    }
    for(int i=0;i<k;i++)
    {
        for(int j=k-1;j>i;j--)
        {
            if(ran[j].s>ran[j-1].s)
            {
                ranking temp=ran[j];
                ran[j]=ran[j-1];
                ran[j-1]=temp;
            }
        }
    }
    ran[0].r=1;
    for(int i=1;i<k;i++)
    {
        if(ran[i].s==ran[i-1].s)
        {
            ran[i].r=ran[i-1].r;
        }
        else 
        {
            ran[i].r=i+1;
        }
    }
    //可以发现 k其实是多余的 但是这种思想是通用的 单独拿出一个变量来计算新的未知数组的size
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<k;j++)
        {
            if(stu[i].sum==ran[j].s)
            {
                stu[i].rank=ran[j].r;
            }
        }
        cout<<stu[i].name<<" ";
        cout<<fixed<<setprecision(1)<<stu[i].sum<<" ";
        cout<<stu[i].rank<<endl;
    }
    return 0;
}