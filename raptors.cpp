#include <iostream>
#include <cmath>
using namespace std;


class Raptor{
public:
  float health, speed; //health ranges from zero to 10
  //  string name;
  float x,y,vx,vy;
  Raptor(){x=0.0; y=0.0;vx=0.0;vy=0.0;};
  Raptor(float,float);
  void Track(Raptor);
  // Still not defining operations on raptors
  //  Raptor operator+(Raptor);
  //Raptor operator-(Raptor);
};


Raptor::Raptor(float a,float b){
  x=a;
  y=b;
  vx=0;
  vy=0;
  speed= 24.0;
  health= 10.0;
}



void Raptor::Track(Raptor RapB){
  /* Raptor track routine
     the raptor tracks RapB, just sets its velocity
     so it runs in a straight line where target is
   */
  Raptor Temp;
  float tspeed;
  //We store relative position
  Temp.vx= (RapB.x-x);
  Temp.vy= (RapB.y-y);
  //get actual distance
  tspeed= sqrt(Temp.vx*Temp.vx+Temp.vy*Temp.vy);
  //normalize vector and mltiply by raptor speed
  vx=Temp.vx*speed/tspeed;
  vy=Temp.vy*speed/tspeed;
}

int main ()
{
  int i=0,j=0, N=100;
  float dt=0.05, t;
  Raptor player(40,40), Charlie(0,0), Temp;
  player.vx= 4.0;
  player.vy= -4.0;
  player.speed=sqrt(player.vx*player.vx+player.vy*player.vy);
  

  //Initial data
  t=i*dt;
  cout <<t<<"\t"<<player.x<<"\t"<<player.y<<"\t"<<Charlie.x<<"\t"<<Charlie.y<<endl;

  // RUN!!
  for(i=1;i<N;i++){

    t=i*dt;

    Charlie.Track(player);
      //    Charlie.vx=Temp.vx;
      //    Charlie.vy=Temp.vy;

    player.x+= player.vx*dt;
    player.y+= player.vy*dt;

    Charlie.x+= Charlie.vx*dt;
    Charlie.y+= Charlie.vy*dt;

    cout <<t<<"\t"<<player.x<<"\t"<<player.y<<"\t"<<Charlie.x<<"\t"<<Charlie.y<<endl;
    
  }

  //cout<<"Player is death, Charlie wins \n";

  return 0;
}
