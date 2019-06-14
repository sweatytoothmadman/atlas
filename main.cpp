#include <bits/stdc++.h>
using namespace std;
vector< int > countries[26][26];
// ar[i][j] is an array storing countries starting from letter 'a'+i and ending with a+'j'
vector< string >  names;
vector< int > vi;
int co[26];
int number_of_countries_starting_from[26];
map< string , int > m;
void input(){
    string u[]={"Afghanistan","Albania","Algeria","Andorra","Angola","Antigua & Barbuda","Argentina","Armenia","Australia","Austria","Azerbaijan","Bahamas","Bahrain","Bangladesh","Barbados","Belarus","Belgium","Belize","Benin","Bhutan","Bolivia","Bosnia Herzegovina","Botswana","Brazil","Brunei","Bulgaria","Burkina","Burundi","Cambodia","Cameroon","Canada","Cape Verde","CentralAfricanRepublic","Chad","Chile","China","Colombia","Comoros","Congo","CongoDemocraticRepublic","Costa Rica","Croatia","Cuba","Cyprus","Czech Republic","Denmark","Djibouti","Dominica","Dominican Republic","East Timor","Ecuador","Egypt","El Salvador","Equatorial Guinea","Eritrea","Estonia","Ethiopia","Fiji","Finland","France","Gabon","Gambia","Georgia","Germany","Ghana","Greece","Grenada","Guatemala","Guinea","Guinea-Bissau","Guyana","Haiti","Honduras","Hungary","Iceland","India","Indonesia","Iran","Iraq","Ireland","Israel","Italy","IvoryCoast","Jamaica","Japan","Jordan","Kazakhstan","Kenya","Kiribati","NorthKorea","SouthKorea","Kosovo","Kuwait","Kyrgyzstan","Laos","Latvia","Lebanon","Lesotho","Liberia","Libya","Liechtenstein","Lithuania","Luxembourg","Macedonia","Madagascar","Malawi","Malaysia","Maldives","Mali","Malta","MarshallIslands","Mauritania","Mauritius","Mexico","Micronesia","Moldova","Monaco","Mongolia","Montenegro","Morocco","Mozambique","Myanmar","Burma","Namibia","Nauru","Nepal","Netherlands","Newzealand","Nicaragua","Niger","Nigeria","Norway","Oman","Pakistan","Palau","Panama","Papua New Guinea","Paraguay","Peru","Philippines","Poland","Portugal","Qatar","Romania","Russia","Rwanda","StKitts","Nevis","St Lucia","Saint Vincent & the Grenadines","Samoa","San Marino","Sao Tome & Principe","Saudi Arabia","Senegal","Serbia","Seychelles","Sierra Leone","Singapore","Slovakia","Slovenia","Solomon Islands","Somalia","SouthAfrica","SouthSudan","Spain","SriLanka","Sudan","Suriname","Swaziland","Sweden","Switzerland","Syria","Taiwan","Tajikistan","Tanzania","Thailand","Togo","Tonga","Trinidad & Tobago","Tunisia","Turkey","Turkmenistan","Tuvalu","Uganda","Ukraine","UnitedArabEmirates","UnitedKingdom","UnitedStates","Uruguay","Uzbekistan","Vanuatu","Vatican city","Venezuela","Vietnam","Yemen","Zambia","Zimbabwe","_"};
    string a;
    int index=0;
    int i=0;
    while(1){
        a=u[i++];
        if(a=="_")break;
        for(int i=0;i<a.length();i++)
            if(a[i]>='A'&&a[i]<='Z')a[i]=a[i]-'A'+'a';
        int len=a.length();
        if(!(a[0]>='a'&&a[0]-'a'<26)){
        	continue;
		}
		 if(!(a[len-1]>='a'&&a[len-1]-'a'<26)){
        	continue;
		}
        countries[a[0]-'a'][a[len-1]-'a'].push_back(index);
        names.push_back(a);
        m[a]=index;
        vi.push_back(0);
        number_of_countries_starting_from[a[0]-'a']++;
        index++;
    }
    vector< pair< int, int > > ad;
    for(int i=0;i<26;i++){
        ad.push_back(make_pair(number_of_countries_starting_from[i],i));
    }
    sort(ad.begin(),ad.end());
    reverse(ad.begin(),ad.end());
    for(int i=0;i<26;i++)
        co[i]=ad[i].second;

}

int main() {

   input();
    cout<<"Hey there , You want to play atlas \n So lets play atlas \n First choose the level you want to compete with me in a game of atlas \n Easy Medium Hard\n ";
     string a;
    cin>>a;
    cout<<"hmmm, so you want to play at "<<a<<" level, Best of luck  \n Let the games begin \n You start off by saying a country of your chance\n ";
    char pr;
    int l=0;
    if(a[0]=='H')l=25;
    if(a[0]=='L')l=1;
    if(a[0]=='M')l=13;
    int fl=1; int z=0;
    while(fl){
        cout<<"Press 1 to stop playing this super cool game\n";
        if(z)
    {
        cout<<"To continue playing name a country which hasn't been said before starting with letter "<<char(pr-'a'+'A')<<"\n";
    }
    else cout<<"To continue playing Name a country of your choice \n ";
        string country;
        cin>>country;
        for(int i=0;i<country.length();i++)
            if(country[i]>='A'&&country[i]<='Z')country[i]=country[i]-'A'+'a';

         if(country[0]=='1')break;
        if(m.find(country)==m.end()){
            cout<<"This is not a country \n";
            fl=0;
            continue;
        }
        if(z&&((country[0]-'a')!=pr-'a')){
        	cout<<"You cheated , Bye Bye\n";
        	break;
		}
		if(vi[m[country]]){
			cout<<"This country has already been said in the game \n You lost\n";
			return 0;
		}
        z++;
        int len=country.length();
        vi[m[country]]=1;
        pr=country[len-1];
        int fl=0;

        for(int r=l;r<26;r++){
            for(int k=0;k<countries[pr-'a'][co[r]].size();k++){
            if(!vi[countries[pr-'a'][co[r]][k]]){
                cout<<names[countries[pr-'a'][co[r]][k]]<<"\n";
                vi[countries[pr-'a'][co[r]][k]]=1;
                int len=names[countries[pr-'a'][co[r]][k]].length();
                pr=names[countries[pr-'a'][co[r]][k]][len-1];
                fl=1;
                break;
            }
        }
         if(fl)break;
         }

        if(!fl){
            for(int r=l-1;r>=0;r--)
        {
            for(int k=0;k<countries[pr-'a'][co[r]].size();k++){
            if(!vi[countries[pr-'a'][co[r]][k]]){
                cout<<names[countries[pr-'a'][co[r]][k]]<<"\n";
                vi[countries[pr-'a'][co[r]][k]]=1;
                int len=names[countries[pr-'a'][co[r]][k]].length();
                pr=names[countries[pr-'a'][co[r]][k]][len-1];
                fl=1;
                break;
            }
        }
            if(fl)break;}
        }
        if(!fl){
            cout<<"Congratulation you are a true champion\n"; break;
        }
        else cout<<"Its your chance\n";
    }
    cout<<"The Game has ended \n Have a nice day\n";

        return 0;
}
