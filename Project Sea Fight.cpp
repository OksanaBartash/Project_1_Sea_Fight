// Playing "SEA  FIGHT":
#include <iostream> 
#include <windows.h>
#include <Math.h>
#include <ctime>
#include <conio.h> 
#include <string> 
#include <fstream> 
#include <unistd.h>

using namespace std;

const int N=10; 

int ships_id=1; 
int ships[10]={0}; 
int counter=0; 

void set_rand_ships(int map[N][N], int size_ship, int num_ships)
	{
		int x, y; 
		int dir=0;  
		int count_ship=0; 
		
		int count_tact=0; 
			
//==================================================================================================================
		
		while (count_ship<num_ships)
		{
			count_tact++; 
			if (count_tact>1000)
			{
				break;
			}
						
			x=rand()%N;
			y=rand()%N;
				
			int temp_x=x;
			int temp_y=y;
					
			dir=rand()%4; 
			
			bool setting_is_possible=1; 
			
			for (int i=0; i<size_ship; i++) 
			{
				if (x<0 || y<0 || x>=N || y>=N)  
				{
				setting_is_possible=0;
				break;	
				}
				
				if (map[x  ] [y  ]>=1 ||  
					map[x  ] [y+1]>=1 ||
					map[x  ] [y-1]>=1 ||
					map[x+1] [y  ]>=1 ||
					map[x+1] [y+1]>=1 ||
					map[x+1] [y-1]>=1 ||
					map[x-1] [y  ]>=1 ||
					map[x-1] [y+1]>=1 ||
					map[x-1] [y-1]>=1) 
					{
						setting_is_possible=0; 
						break;		
					}
					
					switch(dir) 
					{
						case 0:
							x++;
							break;
						case 1:
							y++;
							break;
						case 2:
							x--;
							break;
						case 3:
							y--;
							break;
					}
			}
			
			if (setting_is_possible==1) 
			{

				x=temp_x; 
				y=temp_y;
				
				for (int i=0; i<size_ship; i++) 
				{
					map[x][y]=ships_id; 
					
					switch(dir) 
					{
						case 0:
							x++;
							break;
						case 1:
							y++;
							break;
						case 2:
							x--;
							break;
						case 3:
							y--;
							break;
					}

				}
				ships[ships_id]=size_ship; 
				ships_id++; 
				count_ship++; 
			}		
		}
	}
//================================================================================================================	
	void map_show (int map[N][N], int mask[N][N])
	{
		
		cout<<" ";
			
		for (int i=0; i<N; i++)	
		{
			cout<<i<<" "; 
		}
		cout<<endl;
			
		
		for (int i=0; i<N; i++) 
		{
			cout<<i;  
						
			for (int j=0; j<N; j++) 
			{
				
				if(mask[j][i]==1)  
				{
					if (map[j][i]==0)  
					{
						cout<<"- ";
					}
					else if (map[j][i]==-1) 
					{
						cout<<"X ";
					}
					else
					{
						cout<<map[j][i]<<" "; 
					}
					
					
				}
				else         
				{				 
					cout<<"  ";  
				}                
				
				if (counter==9) 
				{
					cout<<"You win!";
					break;
				}
			
			}
			cout<<endl;
		}	
		
	}
//===========================================================================================================
		
int main() 
	{
		cout<<"You have to sink a 'Moskal navy' of 9 ships."<<endl;
		cout<<"Shoot carefully, 'x' - horizontally and 'y' - vertically!"<<endl;
		cout<<"Keep in mind that the ships do not touch and there is at least 1 empty space between them."<<endl; 
		cout<<"GOOD LUCK!!!"<<endl<<endl; 
		cout<<"Data regarding ships - ship number / number of decks:"; 
	while (true) 
	{
		int map[N][N]={0}; 
		
		int mask[N][N]={0}; 
		
		set_rand_ships(map, 4, 1); 
		set_rand_ships(map, 3, 2); 
		set_rand_ships(map, 2, 3); 
		set_rand_ships(map, 1, 3); 

		cout<<endl;
		for (int i=0; i<10; i++)
		{
			cout<<i<<" / "<<ships[i]<<endl; 
		}
		
		int x=0, y=0; 

			while (true)
			{
				map_show (map, mask); 
				
				cout<<endl<<"Enter coordinates from 0 to 9 for 'x' and 'y': "<<endl;

				cin>>x;
				cin>>y;
				
				if (x<0 || y<0 || x>9 || y>9) 
				{
					cout<<"Error! You entered incorrect numbers!";
					getch();
				}	
				
				if (map[x][y] >= 1) 
				{
					ships[map[x][y]]--;
					
					if (ships[map[x][y]]<=0)
					{
						cout<<"Killed!"<<endl;
						counter++; 
					}
					else
					{
						cout<<"Injured!"<<endl;
					}	
					map[x][y]=-1; 		
				}
								
			 	else
				{
					cout<<"You missed"<<endl;
				}

				mask[x][y]=1; 	
					
				Sleep(1000); 
				system("CLS"); 
			 } 

		getch(); 
		system("CLS");  
	}
	system("pause");
	return 0;
}
