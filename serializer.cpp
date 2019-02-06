
#include <iostream> 
#include <vector> 
#include<string>
#include<vector>
#include<map>
using namespace std;


class cDataHolder
{
	private:   
		std::vector< map<string,string> >dataBase;
	public:
		std::map<string,string> Info;
		cDataHolder():dataBase(1000) {}; 
		~cDataHolder()
		{
		Info.clear();
		};


		void print() 
		{ 

			vector<map<string,string> >::iterator it;
			for( it = this->dataBase.begin(); it != this->dataBase.end(); ++it)

			{
				map<string, string>::iterator itr;
				for( itr = it->begin(); itr != it->end(); ++itr)
				{
					cout << itr->first << " " << itr->second << endl; //ERROR
				}
				cout<<endl;
			}
		}
		void AddData(string key,string value)
		{
			this->Info[key]=value;
		}
		void PushData()
		{	
			dataBase.push_back(this->Info);
		}
#if 0 

		void updateData(string key, string val)
		{
			for (vector<map<string,string> >::iterator it=this->dataBase.begin(); it != this->dataBase.end(); ++it)
			{ 
				map<string, string>::iterator itr;
		//		for(itr=(*it).begin();itr!=(*it).end();itr++)
 				for( itr = it->begin(); itr != it->end(); ++itr)
				{
					if(itr->first == key)
					{
						itr->second = val;
					}
				}

			}
			cout<<"printing the updated"<<endl;
			print();


		}
#endif
};



int main() 
{ 

	cDataHolder obj; 
	
	obj.AddData("DisplayText","Temperature");
	obj.AddData("terminal","01");	
	obj.AddData("system","LCD");
	obj.AddData("event","alaram");
	obj.PushData();
	obj.print(); 
		
cout<<endl;
cout<<"second object"<<endl;
	
	obj.AddData("DisplayText","pressure");
	obj.AddData("terminal","02");     
	obj.AddData("system","LCD");
	obj.AddData("event","warn");
	obj.PushData();
	obj.print(); 

	return 0; 
} 


