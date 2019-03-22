#include "contact.h"

contact::contact()
{
    firstName = "Louis";
    lastName = "Monfiero";
    phoneNumber = "7142208888";
    address = "99 Santa Monica St.";
    city = "Manila";
    zipCode = "90630";
    state = "California";
}

contact::contact(string fiN, string lN, string pN, string addr, string cT, string zC, string s)
{
    firstName = fiN;
    lastName = lN;
    phoneNumber = pN;
    address = addr;
    city = cT;
    zipCode = zC;
    state = s;
}

void contact::display()
{
    cout<< firstName <<" "<< lastName <<": "<< phoneNumber << "\n" << address + " " + city +", "+ state + " " + zipCode;
}


//I've got absolutely no idea what I'm doing in here kms
// void readFile(vector<string> test)
// {
//     int ccounter = 0;
//     int rcounter = 0;

//     fstream file;
//     string line;
//     file.open("addresses.txt", ios::in);
//     if (file)
//     {
//         while(getline(file, line))
//         {   
//             for (int i = 0; i < line.length(); i++)
//             {   
                    // for (int j = 0; j < 7; j++)
                    // {
                    //     if (j == 1)
                    //     {
                    //         firstName = [j];
                    //     }
                    // }
//                 if ()
//                 {
//                     rcounter++;
//                     ccounter = 0;
//                 }
//                 array[rcounter][ccounter] = line[i];
//                 ccounter++;
//             }
//         }
//         file.close();
//     }
//     else
//     {
//         cout << "File not found" << endl;
//     }
    
// }