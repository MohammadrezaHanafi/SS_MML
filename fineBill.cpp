#include <iostream>
#include <string>
#include <vector>
#include <time.h>
using namespace std;

#include "classes.cpp"


int main(){
	Police police;
	while (1){
		int choice = intGiver ("choose an option: \n1)add new penalty. \n2)show plaque penaltes. \n3)pey penalty. \n4)EXIT \n-->" , 4 , 1);
		
		if (choice == 1){
			
			double ap;
			string plate = plateGiver();
			while (1){
				cout<<"input amount penalty:";
				cin>>ap;
				if (ap>0) break;
				cout<<"incorrect amount of penalty."<<endl;
			}
			police.savePenalty(Penalty(ap, plate));
			cout<<endl<<endl;
			
		}else if (choice == 2){
			
			string plate = plateGiver();
			police.showPenaltes(plate);
			cout<<endl<<endl;
			
		}else if (choice == 3){
			
			int num ;
			while (1){
				cout<<"input num of penalty: ";
				cin>>num;
				if (police.peyPenalty (num)) {
					cout<<"penalty pey successfuly!"<<endl<<endl;
					break;
				}
				cout<<"there is not any penalty with num:"<<num<<" set to our DB!"<<endl;
				if ( !YorN() ) break;
			}
			cout<<endl<<endl;
			
		}else{
			cout<<"GoodBye!"<<endl;
			break;
		}
	}
	return 0;
}