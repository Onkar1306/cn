#include<iostream>
#include<vector>
#include<string>
using namespace std;

struct Data {
    string outlook,temp,humidity,windy,play;
};

int main(){
    vector<Data> dataset={
        {"sunny", "hot", "high", "false", "no"},
{"sunny", "hot", "high", "true", "no"},
{"overcast", "hot", "high", "false", "yes"},
{"rain", "mild", "high", "false", "yes"},
{"rain", "cool", "normal", "false", "yes"},
{"rain", "cool", "normal", "true", "no"},
{"overcast", "cool", "normal", "true", "yes"},
{"sunny", "mild", "high", "false", "no"},
{"sunny", "cool", "normal", "false", "yes"},
{"rain", "mild", "normal", "false", "yes"},
{"sunny", "mild", "normal", "true", "yes"},
{"overcast", "mild", "high", "true", "yes"},
{"overcast", "hot", "normal", "false", "yes"},
{"rain", "mild", "high", "true", "no"}
    };
    
    string o,t,h,w;
    cout<<"Enter the outlook(sunny/overcast/rain): ";
    cin >> o;
    cout<<"Enter the temp(hot/mild/cool): ";
    cin >> t;
    cout<<"Enter the humidity(high/normal): ";
    cin >> h;
    cout<<"Enter the windy(true/false): ";
    cin >> w;
    
    double yesc = 0, noc = 0;
    for(auto &d:dataset){
        if(d.play=="yes") yesc++;
        else noc++;
    }
    
    double pyes = yesc / dataset.size();
    double pno = noc / dataset.size();
    
    double yesoutlook=0,nooutlook = 0;
    double yestemp=0,notemp = 0;
    double yeshumidity=0,nohumidity = 0;
    double yeswindy=0,nowindy = 0;
    
    for(auto &d:dataset){
        if(d.play=="yes"){
            if(d.outlook==o) yesoutlook++;
            if(d.temp==t) yestemp++;
            if(d.humidity==h) yeshumidity++;
            if(d.windy==w) yeswindy++;
        }
        if(d.play=="no"){
            if(d.outlook==o) nooutlook++;
            if(d.temp==t) notemp++;
            if(d.humidity==h) nohumidity++;
            if(d.windy==w) nowindy++;
        }
    }
    
    double pxyes = (yesoutlook/yesc)*(yestemp/yesc)*(yeshumidity/yesc)*(yeswindy/yesc);
    double pxno = (nooutlook/noc)*(notemp/noc)*(nohumidity/noc)*(nowindy/noc);
    
    if(pxyes>pxno) cout << "play='yes'";
    else cout << "play='no'";
    
    return 0;
}