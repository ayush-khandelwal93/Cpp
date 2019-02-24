#include<iostream>
using namespace std;
#include<vector>
class shape
{
public:
    virtual void takeinput()=0;
    virtual void draw()=0;
};
class shapefactory
{
public:
    static vector<shapefactory*> factories;
    shapefactory()
    {
        factories.push_back(this);
    }
    virtual string getshapename()=0;
    virtual shape* createshape()=0;
};
vector<shapefactory*> shapefactory::factories;
class ConsoleUi
{
public:
    void show()
    {
        vector<shape*> shapes;
        int choice;
        while(true)
        {
            cout<<"0: Redraw"<<endl;
            int index=1;
            for(shapefactory* factory : shapefactory::factories)
            {
                cout<<index++<<": "<<factory->getshapename()
                <<endl;
            }
            cout<<"Select a shape: ";
            cin>>choice;
            if(choice==0)
            {
                for(shape* sh: shapes)
                {
                    sh->draw();
                }
            }
            else
            {
                shape* sh=shapefactory :: factories[choice-1]->
                createshape();
                sh->takeinput();
                sh->draw();
                shapes.push_back(sh);
            }
            
        }
    }
};

int main()
{
    ConsoleUi cui;
    cui.show();
}

class circle : public shape
{
    int cx, cy, radius;
    void takeinput()
    {
        cout<<"Enter circle data (cx,cy,radius): ";
        cin>> cx>>cy>>radius;
    }
    void draw()
    {
        cout<<"Draw circle: "<<cx<<" "<<cy<<" "<<radius<<endl;
    }
};
class circlefactory : public shapefactory
{
    string getshapename()
    {
        return "Circle";
    }
    shape* createshape()
    {
        circle* c= new circle();
        return c;
    }
}cf;
class rectangle : public shape
{
    int left, top, width, height; 

	void takeinput()
	{
		cout << "Enter Rectangle Data (left, top, width height): ";
		cin >> left >> top >> width >> height;
	}

	void draw()
	{
		cout << "Draw Rectangle: " << left << " " << top << " " << width << " " << height << endl; 
	}
};
class rectanglefactory : public shapefactory
{
    string getshapename()
    {
        return "rectangle";
    }
    shape* createshape()
    {
        rectangle *r= new rectangle();
        return r;
    }
}rf;