#include <iostream>
#include <string.h>
#include <iomanip>

using namespace std;
int main()
{
    const int MAXemployee =100;
    int employeeID[100];
    string employeeNAME[100];
    char empoyeeSEX[100];
    string employeeDepartment[100];
    int employeeSALARY[100];
    int salary_record[100];
    string damagede_properties[100];
    int ID=0;

    for(int i=0;i<MAXemployee;i++){
        int choice;

        cout<<"Choose what u wanna do:\n\n"<<"1.Add new employee.\n"<<"2.Update employee data.\n"<<"3.Delete emplyee data.\n"<<"4.Search emplpyee.\n"<<"5.Exite this system.\n\n";
        cout<<"Enter ur choice:";
        cin>>choice;
        cin.ignore();

        if(choice==1){
            string name,department;
            int salary;
            char sex;

            cout<<"Enter employee name:";
            getline(cin,name);
            cin.ignore();
            employeeNAME[ID]=name;

            cout<<"Enter employee's sex:";
            cin>>sex;
            cin.ignore();
            empoyeeSEX[ID]=sex;

            cout<<"Enter employee department:";
            getline(cin,department);
            cin.ignore();
            employeeDepartment[ID]=department;

            cout<<"Enter employee first month salary:";
            cin>>salary;
            cin.ignore();
            employeeSALARY[ID]=salary;

            ID++;//ID number start from 1
            employeeID[ID-1]=ID;
            cout<<"This employee ID is:"<<ID<<endl;
            }
                    
        else if(choice==2){   

            int id;
            cout<<"Enter customer ID:";
            cin>>id;

            if(id>0 && id<=ID){
                int choice2;
                cout<<"What u wanna update:\n"<<"1.pay salary.\n"<<"2.Deduct from salary.\n";
                cin>>choice2;

                if(choice2==1){
                    int salary2;

                    cout<<"This employee monthly salary is: "<<employeeSALARY[id-1]<<endl;
                    cout<<"pay his/her salary:";
                    cin>>salary2;
                    salary_record[id-1]+=salary2;
                    
                }else if(choice2==2){
                    int choice3;
                    cout<<"What is his/her faul:\n"<<"1.Left work for full day/day's?\n"<<"2.Property damage?\n";
                    cin>>choice3;

                    if(choice3==1){
                        int deductionrate,days,deduction_amount,newsalary;
                        
                        deductionrate=employeeSALARY[id-1]/30;

                        cout<<"Enter amount of days he/she left in this month:";
                        cin>>days;

                        deduction_amount = (deductionrate*days);
                        newsalary = employeeSALARY[id-1] - deduction_amount;

                        cout<<"Empoyee salary deduced by: "<<deduction_amount<<endl<<"His/Her remaining salary is: "<<newsalary<<endl;

                    }else if(choice3==2){
                        string propertie;
                        int cost,Newsalary;

                        cout<<"Enter type of propertie/s:";
                        getline(cin,propertie);
                        cin.ignore();
                        damagede_properties[id-1]=propertie;

                        cout<<"Enter the damage cost:";
                        cin>>cost;
                        Newsalary=employeeSALARY[id-1]-cost;
                        
                        cout<<"This employee remaining salary is:"<<Newsalary;

                    }else{
                        cout<< "invalid input!";
                    }

                }else{
                    cout<< "invalid input!";
                }

            }else{
                cout<<"This ID doesn't exist.";
            }

        }
                
        else if(choice ==3){

            int id1;
            cout<<"Enter employee ID that's left this org:";
            cin>>id1;

            for(int i=id1-1;i<ID;i++){
                employeeID[i]=employeeID[i+1];//ID number changed to ID-1 from id1-1 to ID (means it decrease by -1)
                employeeDepartment[i]=employeeDepartment[i+1];
                employeeSALARY[i]=employeeSALARY[i+1];
                damagede_properties[i]=damagede_properties[i+1];
                ID--;
            } 
            cout<<"Employee's ID number is shifted by 1 to the previous ID number start from ID number: "<<id1;
        }

        else if(choice==4){

            int id2;
            cout<<"Enter ID number inorder to search empoyee:";
            cin>>id2;

            if(id2>0&&id2<=ID){
                cout<<"These 👇🏼 are this empoyee data in our org:"<<endl;
                cout<<"employeeNAME: is "<<employeeNAME[id2-1]<<endl;
                cout<<"empoyeeSEX: is "<<empoyeeSEX[id2-1]<<endl;
                cout<<"employeeDepartment: at "<<employeeDepartment[id2-1]<<endl;
                cout<<"employeeSALARY: is "<<employeeSALARY[id2-1]<<endl;
                
            }else{
                cout<<"Invalid ID number!"<<endl;
            }
        }

        else{
                    cout<<"Exiting program...";
                    return 0;
                    }
        
    }
    return 0;
}