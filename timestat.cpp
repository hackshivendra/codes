#include <iostream>
#include <simplecpp>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;
int main()
{
    std::string m,s,var;

    float minu, sec;
    vector<float> v_real,v_sys,v_user;
    ifstream file_("timestat.txt");

    if(file_.is_open())
    {
        while((file_ >> var >> minu >> m >> sec >> s))
        {

            cout<<var;
            if(var=="real")
            {
                v_real.push_back(minu*60+sec);
                cout<<v_real[0];
            }
            else if(var=="sys")
            {
                v_sys.push_back(minu*60+sec);
            }
            else if(var=="real")
            {
                v_real.push_back(minu*60+sec);
            }
        }
        file_.close();
    }
    float sum_real=0,sum_user=0,sum_sys=0,avg_real,avg_sys,avg_user;
    for(int i=0; i<100; i++)
    {
        sum_real=sum_real+v_real[i];
        sum_user=sum_user+v_user[i];
        sum_sys=sum_sys+v_sys[i];
    }
    avg_real=sum_real/100;
    avg_user=sum_user/100;
    avg_sys=sum_sys/100;

    float sum2_real=0,sum2_user=0,sum2_sys=0,sd_real,sd_sys,sd_user;
    for(int i=0; i<100; i++)
    {
        sum2_real=sum2_real+(v_real[i]-avg_real)*(v_real[i]-avg_real);
        sum2_sys=sum2_sys+(v_sys[i]-avg_sys)*(v_sys[i]-avg_sys);
        sum2_user=sum2_user+(v_user[i]-avg_user)*(v_user[i]-avg_user);

        sd_real=pow( sum2_real/100,0.5);
        sd_sys=pow( sum2_sys/100,0.5);
        sd_user=pow( sum2_user/100,0.5);

        int count_real=0 , count_sys=0 , count_user=0;
        for(int i=0; i<100; i++)
        {
            if(abs(v_real[i]-avg_real)< sd_real)
            {

                count_real++;
            }
            if(abs(v_sys[i]-avg_sys)< sd_sys)
            {

                count_sys++;
            }
            if(abs(v_user[i]-avg_user)< sd_user)
            {

                count_user++;
            }
        }

        cout<<"Number of runs :"<<100<<endl;
        cout<<"Average time statistics:"<<endl;
        cout<<"real:"<<avg_real<<"  "<<"sys"<<avg_sys<<"  "<<"user"<<avg_user<<endl;
        cout<<"standard deviation of time statistics:"<<endl;
        cout<<"real:"<<sd_real<<"  "<<"sys"<<sd_sys<<"  "<<"user"<<sd_user<<endl;
        cout<<"no. of runs within average +/- standard deviation:"<<endl;
        cout<<"real:"<<count_real<<"  "<<"sys"<<count_sys<<"  "<<"user"<<count_user<<endl;
    }
