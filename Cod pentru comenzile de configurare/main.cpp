#include <iostream>
#include <ctime>
#include <stdlib.h>
#include <string>

using namespace std;


int main()
{
    string value, hostname, ipswitch, retea, gateway, caz, caz1, caz2, tip_switch, vlan_nume[100];
    int t = 0,cont=0, masca, bin_masca[4], nr_vlan, vlan_val[100], nr_porturi, mac_max[100], global_admin, global_NULL;
    string v[100];

    int porturi[27]={0};
    int vlan_admin[100];

    int nr_ACC,nr_D,nr_C;
    //porturi[1] e de fapt fa0/1
    //porturi[24] e de fapt fa0/24
    //porturi[25] e de fapt giga 0/1

    cout<<"Este router sau switch: ";
    cin>> caz;
    if(caz=="switch")
    {
        cout<<"\nAvem IPv6 (da sau nu): ";
        cin>> caz1;
        if(caz1=="nu")
        {
            cout<<"\nAvem VLAN-uri pe switch (da sau nu): ";
            cin>> caz2;
            if(caz2=="nu")
            {
                system("cls");
                cout << "DATA SI ORA" << endl << endl;
                cout << "ORA : ";//v[0]
                cin >> v[t];
                t++;
                cout << "MINUTE : ";//v[1]
                cin >> v[t];
                t++;
                cout << "SECUNDE : ";//v[2]
                cin >> v[t];
                t++;
                cout << "ZI : ";//v[3]
                cin >> v[t];
                t++;
                cout << "LUNA(ex: JAN/FEB) : ";//v[4]
                cin >> v[t];
                t++;
                cout << "AN : ";//v[5]
                cin >> v[t];
                system("cls");

                cout << "Introduceti hostname: ";
                cin >> hostname;
                cout << "\nIntroduceti ip-ul SWITCH-ului: ";
                cin >> ipswitch;
                cout << "Introduceti gateway: ";
                cin >> gateway;
                cout << "Introduceti NA: ";
                cin >> retea;
                cout << "Introduceti numarul de biti pentru masca: ";
                cin >> masca;
                int loc_masca=masca;
                while(cont<4)
                {
                    if(loc_masca>=8)
                    {
                        bin_masca[cont]=255;
                        loc_masca-=8;
                    }
                    else if(loc_masca==7)
                    {
                        bin_masca[cont]=254;
                        loc_masca-=7;
                    }
                    else if(loc_masca==6)
                    {
                        bin_masca[cont]=252;
                        loc_masca-=6;
                    }
                    else if(loc_masca==5)
                    {
                        bin_masca[cont]=248;
                        loc_masca-=5;
                    }
                    else if(loc_masca==4)
                    {
                        bin_masca[cont]=240;
                        loc_masca-=4;
                    }
                    else if(loc_masca==3)
                    {
                        bin_masca[cont]=224;
                        loc_masca-=3;
                    }
                    else if(loc_masca==2)
                    {
                        bin_masca[cont]=192;
                        loc_masca-=2;
                    }
                    else if(loc_masca==1)
                    {
                        bin_masca[cont]=128;
                        loc_masca-=1;
                    }
                    else if(loc_masca==0)
                        bin_masca[cont]=0;

                    cont++;
                }
            }
            else
            {
                system("cls");
                cout << "Introduceti numarul de switchuri ACC: ";
                cin >> nr_ACC;
                cout << "\nIntroduceti numarul de switchuri D: ";
                cin >> nr_D;
                cout << "\nIntroduceti numarul de switchuri C: ";
                cin >> nr_C;
                cout << "\nNumarul de VLAN-uri (inclusiv VLAN NULL): ";
                cin >> nr_vlan;
                for(int i=0;i<nr_vlan;i++)
                {
                    cout<<"\n\t=======================================\n";
                    cout<<"\n\tIntroduceti numele VLAN-ului (toate CAPS): ";
                    cin>>vlan_nume[i];
                    cout<<"\n\tIntroduceti valoarea VLAN-ului: ";
                    cin>>vlan_val[i];
                    cout<<"\n\tCate adrese mac poate sa retina maxim: ";
                    cin>>mac_max[i];
                    if(vlan_nume[i]!="NULL")
                    {
                        cout<<"\n\tEste administrativ (da sau nu): ";
                        string local;
                        cin>>local;
                        if(local=="da")
                        {
                            vlan_admin[i]=1;
                            global_admin=i;
                        }
                        else
                            vlan_admin[i]=0;
                        cout<<"\n\n\t\t\tLEGENDA";
                        cout<<"\n\t\tfa 0/1->1";
                        cout<<"\n\t\tfa 0/2->2";
                        cout<<"\n\t\t---------";
                        cout<<"\n\t\tfa 0/24->24";
                        cout<<"\n\t\tgiga 0/1->25";
                        cout<<"\n\t\tgiga 0/2->26\n";
                        cout<<"\n\tIntroduceti numarul de porturi VLAN-ului: ";
                        cin>>nr_porturi;
                        cout<<"\n\tIntroduceti porturile VLAN-ului: ";
                        int port_local;
                        for(int j=0; j<nr_porturi;j++)
                        {
                            cin>>port_local;
                            porturi[port_local]=vlan_val[i];
                        }
                    }
                    else
                    {
                        vlan_admin[i]=2;
                        global_NULL=i;
                    }
                }
                cout<<endl<<endl;
            }
        }
        else
        {
            system("cls");
            cout << "DATA SI ORA" << endl << endl;
            cout << "ORA : ";//v[0]
            cin >> v[t];
            t++;
            cout << "MINUTE : ";//v[1]
            cin >> v[t];
            t++;
            cout << "SECUNDE : ";//v[2]
            cin >> v[t];
            t++;
            cout << "ZI : ";//v[3]
            cin >> v[t];
            t++;
            cout << "LUNA(ex: JAN/FEB) : ";//v[4]
            cin >> v[t];
            t++;
            cout << "AN : ";//v[5]
            cin >> v[t];
            system("cls");

            cout << "Introduceti hostname: ";
            cin >> hostname;
        }
    }

    if(caz=="switch")
    {
        if(caz2=="da")
        {
            for(int l=0;l<nr_ACC;l++)
            {
                system("pause");
                system("cls");
                cout << "----------------------SWITCH SwACC"<<l+1<<"----------------------" << endl << endl;
                t=0;
                cout << "\nDATA SI ORA" << endl << endl;
                cout << "ORA : ";//v[0]
                cin >> v[t];
                t++;
                cout << "MINUTE : ";//v[1]
                cin >> v[t];
                t++;
                cout << "SECUNDE : ";//v[2]
                cin >> v[t];
                t++;
                cout << "ZI : ";//v[3]
                cin >> v[t];
                t++;
                cout << "LUNA(ex: JAN/FEB) : ";//v[4]
                cin >> v[t];
                t++;
                cout << "AN : ";//v[5]
                cin >> v[t];
                system("cls");

                cout << "----------------------SWITCH SwACC"<<l+1<<"----------------------" << endl << endl<<endl;

                cout << "enable" << endl;
                cout << "clock set ";
                for(int i = 0 ; i < 2 ; i++)
                {
                    if(i != 2)
                    {
                        cout << v[i] << ":";
                    }
                    else
                    {
                        cout << v[i] << " ";
                    }
                }

                for(int i = 2 ; i <= t ; i++)
                {
                    cout << v[i] << " ";
                }
                cout << endl;
                cout << "configure terminal" << endl;
                cout << "hostname SwACC"<<l+1<< endl;
                cout << "no ip domain-lookup" << endl;
                cout << "no cdp run" << endl;
                cout << "service password-encryption" << endl;
                cout << "enable secret ciscosecpa55" << endl;
                cout << "enable password ciscoenapa55" << endl;
                cout << "banner motd *Joi la ora 12:00 sedinta*" << endl;
                cout << "line console 0" << endl;
                cout << "password ciscoconpa55" << endl;
                cout << "login" << endl;
                cout << "logging synchronous" << endl;
                cout << "exec-timeout 20 20" << endl;
                cout << "exit" << endl;
                cout << "line vty 0 15" << endl;
                cout << "password ciscovtypa55" << endl;
                cout << "login " << endl;
                cout << "logging synchronous" << endl;
                cout << "exec-timeout 25 25" << endl;
                cout << "exit" << endl;
                cout << "ip domain-name cti.ro" << endl;
                cout << "username Admin01 privilege 15 secret Admin01pa55" << endl;
                cout << "line vty 0 15" << endl;
                cout << "transport input ssh" << endl;
                cout << "login local" << endl;
                cout << "exit" << endl;
                cout << "crypto key generate rsa" << endl;
                cout << "2048" << endl;
                for(int i=0; i<nr_vlan; i++)
                {
                    cout << "vlan " << vlan_val[i] << endl;
                    cout << "name " << vlan_nume[i] << endl;
                    cout << "exit" << endl;
                }
                for(int i=0; i<nr_vlan; i++)
                {
                    if(vlan_admin[i]==0)
                    {
                        cout << "interface range ";
                        for(int j=1; j<27; j++) //pentru interfete: fa0/1-24+giga0/1-2= 26 de pozitii in vector
                        {
                            if(porturi[j]==vlan_val[i])
                            {
                                if(j<=24)
                                    cout<<"fa 0/"<<j<<",";
                                else
                                    cout<<"giga 0/"<<j-24<<",";
                            }
                        }
                        cout<<"\b \b"<<endl;
                        cout<<"switchport mode access"<<endl;
                        cout<<"switchport access vlan "<<vlan_val[i]<<endl;
                        cout<<"switchport port-security"<<endl;
                        cout<<"switchport port-security maximum "<<mac_max[i]<<endl;
                        cout<<"switchport port-security mac-address sticky"<<endl;
                        cout<<"switchport port-security violation shutdown"<<endl;
                        cout<<"exit"<<endl;
                    }
                    else if(vlan_admin[i]==1)
                    {
                        cout << "interface range ";
                        for(int j=1; j<27; j++) //pentru interfete: fa0/1-24+giga0/1-2= 26 de pozitii in vector
                        {
                            if(porturi[j]==vlan_val[i])
                            {
                                if(j<=24)
                                    cout<<"fa 0/"<<j<<",";
                                else
                                    cout<<"giga 0/"<<j-24<<",";
                            }
                        }
                        cout<<"\b \b"<<endl;
                        cout<<"switchport mode trunk"<<endl;
                        cout<<"switchport trunk native vlan "<<vlan_val[i]<<endl;
                        cout<<"switchport trunk allowed vlan ";
                        for(int p=0; p<nr_vlan; p++)
                            if(vlan_admin[p]!=2)
                                cout<<vlan_val[p]<<",";
                        cout<<"\b \b"<<endl;
                        cout<<"exit"<<endl;
                    }
                    else
                    {
                        cout << "interface range ";
                        for(int j=1; j<27; j++) //pentru interfete: fa0/1-24+giga0/1-2= 26 de pozitii in vector
                        {
                            if(porturi[j]==0)
                            {
                                if(j<=24)
                                    cout<<"fa 0/"<<j<<",";
                                else
                                    cout<<"giga 0/"<<j-24<<",";
                            }
                        }
                        cout<<"\b \b"<<endl;
                        cout<<"switchport mode access"<<endl;
                        cout<<"switchport access vlan "<<vlan_val[i]<<endl;
                        cout<<"switchport port-security"<<endl;
                        cout<<"switchport port-security maximum "<<mac_max[i]<<endl;
                        cout<<"switchport port-security mac-address sticky"<<endl;
                        cout<<"switchport port-security violation shutdown"<<endl;
                        cout<<"shutdown"<<endl;
                        cout<<"exit"<<endl;
                    }
                }
                cout << "end" << endl;
                cout << "copy running-config startup-config" << endl << endl;
                cout<<endl<<endl;
            }
            for(int l=0;l<nr_D;l++)
            {
                system("pause");
                system("cls");
                cout << "----------------------SWITCH SwD"<<l+1<<"----------------------" << endl << endl;
                t=0;
                cout << "\nDATA SI ORA" << endl << endl;
                cout << "ORA : ";//v[0]
                cin >> v[t];
                t++;
                cout << "MINUTE : ";//v[1]
                cin >> v[t];
                t++;
                cout << "SECUNDE : ";//v[2]
                cin >> v[t];
                t++;
                cout << "ZI : ";//v[3]
                cin >> v[t];
                t++;
                cout << "LUNA(ex: JAN/FEB) : ";//v[4]
                cin >> v[t];
                t++;
                cout << "AN : ";//v[5]
                cin >> v[t];
                system("cls");

                cout << "----------------------SWITCH SwD"<<l+1<<"----------------------" << endl << endl<<endl;
                cout << "enable" << endl;
                cout << "clock set ";
                for(int i = 0 ; i < 2 ; i++)
                {
                    if(i != 2)
                    {
                        cout << v[i] << ":";
                    }
                    else
                    {
                        cout << v[i] << " ";
                    }
                }

                for(int i = 2 ; i <= t ; i++)
                {
                    cout << v[i] << " ";
                }
                cout << endl;
                cout << "configure terminal" << endl;
                cout << "hostname SwD"<<l+1<< endl;
                cout << "no ip domain-lookup" << endl;
                cout << "no cdp run" << endl;
                cout << "service password-encryption" << endl;
                cout << "enable secret ciscosecpa55" << endl;
                cout << "enable password ciscoenapa55" << endl;
                cout << "banner motd *Joi la ora 12:00 sedinta*" << endl;
                cout << "line console 0" << endl;
                cout << "password ciscoconpa55" << endl;
                cout << "login" << endl;
                cout << "logging synchronous" << endl;
                cout << "exec-timeout 20 20" << endl;
                cout << "exit" << endl;
                cout << "line vty 0 15" << endl;
                cout << "password ciscovtypa55" << endl;
                cout << "login " << endl;
                cout << "logging synchronous" << endl;
                cout << "exec-timeout 25 25" << endl;
                cout << "exit" << endl;
                cout << "ip domain-name cti.ro" << endl;
                cout << "username Admin01 privilege 15 secret Admin01pa55" << endl;
                cout << "line vty 0 15" << endl;
                cout << "transport input ssh" << endl;
                cout << "login local" << endl;
                cout << "exit" << endl;
                cout << "crypto key generate rsa" << endl;
                cout << "2048" << endl;
                for(int i=0; i<nr_vlan; i++)
                {
                    cout << "vlan " << vlan_val[i] << endl;
                    cout << "name " << vlan_nume[i] << endl;
                    cout << "exit" << endl;
                }
                cout << "interface range ";
                for(int j=1; j<27; j++) //pentru interfete: fa0/1-24+giga0/1-2= 26 de pozitii in vector
                {
                    if(porturi[j]!=vlan_val[global_admin])
                    {
                        if(j<=24)
                            cout<<"fa 0/"<<j<<",";
                        else
                            cout<<"giga 0/"<<j-24<<",";
                    }
                }
                cout<<"\b \b"<<endl;
                cout<<"switchport mode access"<<endl;
                cout<<"switchport access vlan "<<vlan_val[global_NULL]<<endl;
                cout<<"switchport port-security"<<endl;
                cout<<"switchport port-security maximum "<<mac_max[global_NULL]<<endl;
                cout<<"switchport port-security mac-address sticky"<<endl;
                cout<<"switchport port-security violation shutdown"<<endl;
                cout<<"shutdown"<<endl;
                cout<<"exit"<<endl;
                cout << "interface range ";
                for(int j=1; j<27; j++) //pentru interfete: fa0/1-24+giga0/1-2= 26 de pozitii in vector
                {
                    if(porturi[j]==vlan_val[global_admin])
                    {
                        if(j<=24)
                            cout<<"fa 0/"<<j<<",";
                        else
                            cout<<"giga 0/"<<j-24<<",";
                    }
                }
                cout<<"\b \b"<<endl;
                cout<<"switchport mode trunk"<<endl;
                cout<<"switchport trunk native vlan "<<vlan_val[global_admin]<<endl;
                cout<<"switchport trunk allowed vlan ";
                for(int p=0; p<nr_vlan; p++)
                    if(vlan_admin[p]!=2)
                        cout<<vlan_val[p]<<",";
                cout<<"\b \b"<<endl;
                cout<<"exit"<<endl;
                cout << "end" << endl;
                cout << "copy running-config startup-config" << endl << endl;
                cout<<endl<<endl;
            }
            for(int l=0;l<nr_C;l++)
            {
                system("pause");
                system("cls");
                cout << "----------------------SWITCH SwC"<<l+1<<"----------------------" << endl << endl;
                t=0;
                cout << "\nDATA SI ORA" << endl << endl;
                cout << "ORA : ";//v[0]
                cin >> v[t];
                t++;
                cout << "MINUTE : ";//v[1]
                cin >> v[t];
                t++;
                cout << "SECUNDE : ";//v[2]
                cin >> v[t];
                t++;
                cout << "ZI : ";//v[3]
                cin >> v[t];
                t++;
                cout << "LUNA(ex: JAN/FEB) : ";//v[4]
                cin >> v[t];
                t++;
                cout << "AN : ";//v[5]
                cin >> v[t];
                system("cls");

                cout << "----------------------SWITCH SwC"<<l+1<<"----------------------" << endl << endl<<endl;
                cout << "enable" << endl;
                cout << "clock set ";
                for(int i = 0 ; i < 2 ; i++)
                {
                    if(i != 2)
                    {
                        cout << v[i] << ":";
                    }
                    else
                    {
                        cout << v[i] << " ";
                    }
                }

                for(int i = 2 ; i <= t ; i++)
                {
                    cout << v[i] << " ";
                }
                cout << endl;
                cout << "configure terminal" << endl;
                cout << "hostname SwC"<<l+1<< endl;
                cout << "no ip domain-lookup" << endl;
                cout << "no cdp run" << endl;
                cout << "service password-encryption" << endl;
                cout << "enable secret ciscosecpa55" << endl;
                cout << "enable password ciscoenapa55" << endl;
                cout << "banner motd *Joi la ora 12:00 sedinta*" << endl;
                cout << "line console 0" << endl;
                cout << "password ciscoconpa55" << endl;
                cout << "login" << endl;
                cout << "logging synchronous" << endl;
                cout << "exec-timeout 20 20" << endl;
                cout << "exit" << endl;
                cout << "line vty 0 15" << endl;
                cout << "password ciscovtypa55" << endl;
                cout << "login " << endl;
                cout << "logging synchronous" << endl;
                cout << "exec-timeout 25 25" << endl;
                cout << "exit" << endl;
                cout << "ip domain-name cti.ro" << endl;
                cout << "username Admin01 privilege 15 secret Admin01pa55" << endl;
                cout << "line vty 0 15" << endl;
                cout << "transport input ssh" << endl;
                cout << "login local" << endl;
                cout << "exit" << endl;
                cout << "crypto key generate rsa" << endl;
                cout << "2048" << endl;
                for(int i=0; i<nr_vlan; i++)
                {
                    cout << "vlan " << vlan_val[i] << endl;
                    cout << "name " << vlan_nume[i] << endl;
                    cout << "exit" << endl;
                }
                cout << "interface range ";
                for(int j=1; j<27; j++) //pentru interfete: fa0/1-24+giga0/1-2= 26 de pozitii in vector
                {
                    if(porturi[j]!=vlan_val[global_admin])
                    {
                        if(j<=24)
                            cout<<"fa 0/"<<j<<",";
                        else
                            cout<<"giga 0/"<<j-24<<",";
                    }
                }
                cout<<"\b \b"<<endl;
                cout<<"switchport mode access"<<endl;
                cout<<"switchport access vlan "<<vlan_val[global_NULL]<<endl;
                cout<<"switchport port-security"<<endl;
                cout<<"switchport port-security maximum "<<mac_max[global_NULL]<<endl;
                cout<<"switchport port-security mac-address sticky"<<endl;
                cout<<"switchport port-security violation shutdown"<<endl;
                cout<<"shutdown"<<endl;
                cout<<"exit"<<endl;
                cout << "interface range ";
                for(int j=1; j<27; j++) //pentru interfete: fa0/1-24+giga0/1-2= 26 de pozitii in vector
                {
                    if(porturi[j]==vlan_val[global_admin])
                    {
                        if(j<=24)
                            cout<<"fa 0/"<<j<<",";
                        else
                            cout<<"giga 0/"<<j-24<<",";
                    }
                }
                cout<<"\b \b"<<endl;
                cout<<"switchport mode trunk"<<endl;
                cout<<"switchport trunk native vlan "<<vlan_val[global_admin]<<endl;
                cout<<"switchport trunk allowed vlan ";
                for(int p=0; p<nr_vlan; p++)
                    if(vlan_admin[p]!=2)
                        cout<<vlan_val[p]<<",";
                cout<<"\b \b"<<endl;
                cout<<"exit"<<endl;
                cout << "end" << endl;
                cout << "copy running-config startup-config" << endl << endl;
                cout<<endl<<endl;
            }
        }
        else
        {
            system("cls");
            cout << "----------------------SWITCH----------------------" << endl << endl;

            cout << "enable" << endl;
            cout << "clock set ";
            for(int i = 0 ; i < 2 ; i++)
            {
                if(i != 2)
                {
                    cout << v[i] << ":";
                }
                else
                {
                    cout << v[i] << " ";
                }
            }

            for(int i = 2 ; i <= t ; i++)
            {
                cout << v[i] << " ";
            }
            cout << endl;
            cout << "configure terminal" << endl;
            cout << "hostname "<< hostname << endl;
            cout << "no ip domain-lookup" << endl;
            cout << "no cdp run" << endl;
            cout << "service password-encryption" << endl;
            cout << "enable secret ciscosecpa55" << endl;
            cout << "enable password ciscoenapa55" << endl;
            cout << "banner motd *Joi la ora 12:00 sedinta*" << endl;
            cout << "line console 0" << endl;
            cout << "password ciscoconpa55" << endl;
            cout << "login" << endl;
            cout << "logging synchronous" << endl;
            cout << "exec-timeout 20 20" << endl;
            cout << "exit" << endl;
            cout << "line vty 0 15" << endl;
            cout << "password ciscovtypa55" << endl;
            cout << "login " << endl;
            cout << "logging synchronous" << endl;
            cout << "exec-timeout 25 25" << endl;
            cout << "exit" << endl;
            cout << "ip domain-name cti.ro" << endl;
            cout << "username Admin01 privilege 15 secret Admin01pa55" << endl;
            cout << "line vty 0 15" << endl;
            cout << "transport input ssh" << endl;
            cout << "login local" << endl;
            cout << "exit" << endl;
            cout << "crypto key generate rsa" << endl;
            cout << "2048" << endl;
            if(caz1=="nu")
            {
                cout << "ip default-gateway " << gateway << endl;
                cout << "interface vlan 1" << endl;
                cout << "description Legatura cu reteaua " << retea << "/" << masca << endl;
                cout << "ip address " << ipswitch << " ";
                for(int i=0; i<3; i++)
                    cout<<bin_masca[i]<<".";
                cout<<bin_masca[3]<< endl;
                cout << "no sh" << endl;
                cout << "exit" << endl;
                cout << "interface range fa 0/1-24" << endl;
                cout << "shutdown" << endl;
                cout << "end" << endl;
                cout << "copy running-config startup-config" << endl << endl;
            }
        }
    }
    else
    {
        system("cls");
        cout << "DATA SI ORA" << endl << endl;
        cout << "ORA : ";//v[0]
        cin >> v[t];
        t++;
        cout << "MINUTE : ";//v[1]
        cin >> v[t];
        t++;
        cout << "SECUNDE : ";//v[2]
        cin >> v[t];
        t++;
        cout << "ZI : ";//v[3]
        cin >> v[t];
        t++;
        cout << "LUNA(ex: JAN/FEB) : ";//v[4]
        cin >> v[t];
        t++;
        cout << "AN : ";//v[5]
        cin >> v[t];
        system("cls");
        cout << "Introduceti hostname: ";
        cin >> hostname;
        system("cls");
        cout << "----------------------ROUTER----------------------" << endl << endl;
        cout << "enable" << endl;
        cout << "clock set ";
        for(int i = 0 ; i < 2 ; i++)
        {
            if(i != 2)
            {
                cout << v[i] << ":";
            }
            else
            {
                cout << v[i] << " ";
            }
        }

        for(int i = 2 ; i <= t ; i++)
        {
            cout << v[i] << " ";
        }
        cout << endl;
        cout << "configure terminal" << endl;
        cout << "hostname " << hostname << endl;
        cout << "no ip domain-lookup" << endl;
        cout << "no cdp run" << endl;
        cout << "service password-encryption" << endl;
        cout << "security passwords min-length 10" << endl;
        cout << "login block-for 60 attempts 3 within 15" << endl;
        cout << "enable secret ciscosecpa55" << endl;
        cout << "enable password ciscoenapa55" << endl;
        cout << "banner login #Acces interzis persoanelor neautorizate !#" << endl;
        cout << "banner motd #Mentenanta in weekend !#" << endl;
        cout << "line console 0" << endl;
        cout << "password ciscoconpa55" << endl;
        cout << "login" << endl;
        cout << "logging synchronous" << endl;
        cout << "exec-timeout 20 20" << endl;
        cout << "exit" << endl;
        cout << "line vty 0 15" << endl;
        cout << "password ciscovtypa55" << endl;
        cout << "login" << endl;
        cout << "logging synchronous" << endl;
        cout << "exec-timeout 20 20" << endl;
        cout << "exit" << endl;
        cout << "ip domain-name cti.ro" << endl;
        cout << "username Admin01 privilege 15 secret Admin01pa55" << endl;
        cout << "line vty 0 15" << endl;
        cout << "transport input ssh" << endl;
        cout << "login local" << endl;
        cout << "exit" << endl;
        cout << "crypto key generate rsa" << endl;
        cout << "2048" << endl;
    }

   return 0;
}
