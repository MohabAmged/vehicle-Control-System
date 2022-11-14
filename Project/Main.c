/*
 * Main.c
 *
 *  Created on: 20 Aug 2022
 *      Author: marwa
 */
#include<stdio.h>
#include "string.h"


typedef struct
{
	int state ;
	int temp;
}State_Temp;

typedef struct
{
	int Engine_state ;
	int AC_state;
	int Speed;
	int Room_Temp;
    int Engine_Controller_State;
    int Engine_Temp;
}States_Menu;


char main_menu(void)
{
	char in;

	printf("a. Turn on the vehicle engine \n");

	printf("b. Turn off the vehicle engine \n");

	printf("c. Quit the system \n");

	scanf(" %c",&in);

	return in;
}


void Print_State(char identifier)
{

	switch (identifier)
	{
	case 'a':
		printf("The Vehicle engine is on \n");
		break;
	case 'b':
		printf("The Vehicle engine is off \n");
	    break;

	case 'c':
		printf("Good Bye \n");
				break;
		default:
				break;
	}
}


 char Sensors_set_menu(void )
{


			printf("a. Turn off the engine \n");

			printf("b. Set the traffic light color. \n");

			printf("c. Set the room temperature (Temperature Sensor) \n");

			printf("d. Set the engine temperature (Engine Temperature Sensor) \n");

			/*printf("e. Display The Engine State Menu \n");*/

			char in;
			scanf(" %c",&in);


	return in;





}

 void Print_Sensors_State(char identifier)
 {

 	switch (identifier)
 	{
 	case 'a':
 		printf("Turn off the engine \n");
 		break;
 	case 'b':
 		printf("Set the traffic light color.\n");
 	    break;

 	case 'c':
 		printf("Set the room temperature (Temperature Sensor) \n");
 				break;
 	case 'd':
 	 		printf("Set the engine temperature (Engine Temperature Sensor) \n");
 	 				break;

 	/*case 'e':
 	 		printf("Display The Engine State Menu \n");
 	 				break;*/
 		default:
 				break;
 	}
 }

int Traffic_Light(void)
{
	char in;
	int speed;
	scanf(" %c",&in);

	if(in =='G' ||in =='g')
	{

      speed=100;
	}
	else if(in =='O' ||in =='o')
		 speed=30;

	else if(in =='R' ||in =='r')
			 speed=0;
	if(in !='R' && in !='r' && in !='O' && in !='o' && in !='G' && in !='g'){
		printf("Enter A Valid Option\n");
		speed=Traffic_Light();
	}


	 	 		printf("The Speed is Set to %d Km/h \n",speed);
       return speed;


}

 State_Temp Temp_Data(void)
{State_Temp Current_Temp;
scanf(" %d",&Current_Temp.temp);
if(Current_Temp.temp<10 )
{
	Current_Temp.state=1;
  Current_Temp.temp=20;
}
else if(Current_Temp.temp>30)
	{Current_Temp.temp=20;
	Current_Temp.state=1;


	}
else
{
	Current_Temp.state=0;
}

printf("The Temperature is Set to %d  \n",Current_Temp.temp);
return Current_Temp;

}

State_Temp Engine_Temp_Data(void)
{State_Temp Engine_Temp;
scanf(" %d",&Engine_Temp.temp);
if(Engine_Temp.temp >100 )
{
	Engine_Temp.state=1;
	Engine_Temp.temp=125;
}
else if(Engine_Temp.temp >30)
	{
	Engine_Temp.state=0;

	}
printf("The Engine Temperature is Set to %d  \n",Engine_Temp.temp);
return Engine_Temp;

}




int main(void)
{
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);
char choice , choice_on;
int speed;
State_Temp Engine,AC;
States_Menu Menu;
Menu.AC_state=0;
Menu.Engine_Controller_State=0;
Menu.Engine_Temp=0;
Menu.Engine_state=0;
Menu.Room_Temp=0;
Menu.AC_state=0;
int Sens1=0,Sens2=0,Sens3=0;
while(1)
{

	choice=main_menu();
	Print_State(choice);
	while(choice=='b')
	{   Menu.Engine_state=0;
		choice=main_menu();
		Print_State(choice);
	}

	while(choice=='a')
	{
		Menu.Engine_state=1;
		choice_on=Sensors_set_menu();
		Print_Sensors_State(choice_on);

		if(choice_on=='a')
		{	Menu.Engine_state=0;
			break;

		}


		else if(choice_on=='b')
			{speed=Traffic_Light();
			 Sens1=1;
			}
		else if(choice_on=='c')
			{AC=Temp_Data();
			Sens2=1;
			}

		else if(choice_on=='d')
			{Engine=Engine_Temp_Data();
			Sens3=1;

			}
		 if(Sens1==1 && Sens2==1 && Sens3==1)
		{

				if(speed==30)
				{
					AC.state=1;
					AC.temp=(int) ((AC.temp)*( (float)5/4))+1;

					Engine.state=1;
					Engine.temp=(int) ((Engine.temp)*( (float)5/4))+1;


				}

				if(Engine.state==1)
				{
					Menu.Engine_Controller_State=1;
				}

				else
					Menu.Engine_Controller_State=0;

				if(AC.state==1)
						{
							Menu.AC_state=1;
						}

						else
							Menu.AC_state=0;



				Menu.Speed=speed;
				Menu.Engine_Temp=Engine.temp;
		        Menu.Room_Temp=AC.temp;

			if(Menu.Engine_state==1)
			      {
			      printf("The Engine is ON \n");
			      }
			      else
			      printf("The Engine is OFF \n");

			   if(Menu.AC_state==1)
			   {
			   printf("The AC is ON \n");
			   }
			   else
			   printf("The AC is OFF \n");

			   printf("Your Speed is %d \n",Menu.Speed);

			   printf("Your Car Room Temperature is %d \n",Menu.Room_Temp);

			   if(Menu.Engine_Controller_State==1)
			   {
			   printf("The Engine Temperature Controller is ON \n");
			   }
			   else
				   printf("The Engine Temperature Controller is OFF \n");

			   printf("Your Engine Temperature is %d \n",Menu.Engine_Temp);



		}

		else if(choice_on != 'a' && choice_on != 'A' && choice_on != 'b' && choice_on != 'B' && choice_on != 'c' && choice_on != 'C' && choice_on != 'd' && choice_on != 'D' )
			{
					printf("Enter A Valid Option \n");
				}





	}
	/*if(Menu.Engine_state==1)
	      {
	      printf("The Engine is ON \n");
	      }
	      else
	      printf("The Engine is OFF \n");

	   if(Menu.AC_state==1)
	   {
	   printf("The AC is ON \n");
	   }
	   else
	   printf("The AC is OFF \n");

	   printf("Your Speed is %d \n",Menu.Speed);

	   printf("Your Car Room Temperature is %d \n",Menu.Room_Temp);

	   if(Menu.Engine_Controller_State==1)
	   {
	   printf("The Engine Temperature Controller is ON \n");
	   }
	   else
		   printf("The Engine Temperature Controller is OFF \n");

	   printf("Your Engine Temperature is %d \n",Menu.Engine_Temp);
*/

   if(choice=='c')
	break;

   if(choice != 'a' && choice != 'b'&& choice && 'c' )
   {
	   printf("Enter A Valid Choice \n");
   }


  }















	return 0;
}

