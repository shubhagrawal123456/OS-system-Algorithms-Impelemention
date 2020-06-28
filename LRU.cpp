#include<iostream>
#include<stdio.h>
using namespace std;

int main()
{
int i,n,page[50],arr[5],k,s,j,large,large_index,dist[5],hit=0,found=0,f;
int nhit=0,nmiss=0;
int m=0;
cout<<"\nEnter the no of pages to be filled in the page table:";
cin>>n;
cout<<"\nEnter the no. of frames:";
cin>>f;
for(i=0;i<n;i++)
 cin>>page[i];
int finish=0; 
int pointer=0;
for(i=0;i<f;i++)
 arr[i]=-1;


//filling the page table
for(i=0;i<n;i++) 
{
 for(j=0;j<=i;j++) 
  {
   if(page[i]!=arr[j])
    hit=0;
   else
   {
   hit=1;
   nhit=nhit+1;
   cout<<"\nPage Hit!";
   break;
   }
  }
 if(hit==0) 
 {
 cout<<"\n j is:"<<j;
 nmiss=nmiss+1;
 cout<<"\nPage Miss!";
 arr[pointer]=page[i];
 pointer=pointer+1;

 }


 cout<<"\nArray:";
 for(k=0;k<f;k++)
 cout<<arr[k]<<" ";
 cout<<"\n";


 if(pointer==f)
 {
 finish=i+1;
 cout<<"\nCompleted filling the frames";
 break;
 }
}



hit=0;
found=0;

for(i=finish;i<n;i++)
{
 for(j=0;j<f;)
 {
  if(page[i]!=arr[j])
  {
   j=j+1;
   hit=0;

  }
  else
  {
   hit=1;
   break;
  }
 }

if(hit==1)
{
 
 cout<<"\nPage hit!";
 nhit=nhit+1;
}
else
{
 cout<<"\nPage miss!";
 nmiss=nmiss+1;

 int index=i;
 for(k=0;k<f;k++)
 {
  cout<<"\nindex:"<<index;
  
  for(m=index;m>0;m--)
  {
   if(arr[k]==page[m])
   {
    dist[k]=index-m;
    cout<<"\n m is "<<m;
    cout<<"\n"<<arr[k]<<"alloted a distance "<<int(dist[k]);

    found=1;
    break;
   }
  }
  if(found==0) 
  {
   dist[k]=99;
   cout<<"\n"<<arr[k]<<"\nalloted a distance 99";
  }
 }
 large=dist[0];
 large_index=0;
 for(s=1;s<f;s++)
 {
  if(large<dist[s])
  {
   large=dist[s];
   large_index=s;

  }
 }
cout<<"\n"<<arr[large_index]<<" stands with largest distance";
arr[large_index]=page[i];

}
cout<<"\n";

for(k=0;k<f;k++)
 cout<<arr[k]<<" ";
}

cout<<"\nNo of hits:"<<nhit;
cout<<"\nNo of misses:"<<nmiss;
return 0;
}
