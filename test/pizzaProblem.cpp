#include <bits/stdc++.h>
using namespace std;

class customer
{
    private:
        string pizzaBase;
        string sauce;
        vector<string> topping;
        string drink;
        string desert;
    public:
        customer(){};
        customer(string pizzaBase,string sauce,vector<string> topping,string drink="",string desert="")
        {
            this->pizzaBase=pizzaBase;
            this->sauce=sauce;
            this->topping=topping;
            this->drink=drink;
            this->desert=desert;   
        }
        void enterDetails()
        {
            string pizzaBase;
            cout<<"Enter the Base of pizza\n";
            getline(cin,pizzaBase);
            string sauce;
            cout<<"Enter the sauce of your choice\n";
            getline(cin,sauce);
            int toppingNumber;
            cout<<"Enter the number of toppings you want\n";
            cin>>toppingNumber;
            vector<string> topping(toppingNumber);
            for(int i=0;i<toppingNumber;++i)
            {
                string currentTopping;
                getline(cin,currentTopping);
                topping[i]=currentTopping;
            }
            string drink="";
            getline(cin,drink);
            string desert="";
            getline(cin,desert);
            this->pizzaBase=pizzaBase;
            this->sauce=sauce;
            this->topping=topping;
            this->drink=drink;
            this->desert=desert; 
        }
        void customerOrderDetails()
        {
            cout<<pizzaBase<<"\n";
            cout<<sauce<<"\n";
            cout<<drink<<"\n";
            cout<<desert<<"\n";
        }

        string getBaseName()
        {
            return pizzaBase;
        }
        string getSauceName()
        {
            return sauce;
        }
        vector<string> getToppingsList()
        {
            return topping;
        }
        string getDrinkName()
        {
            return drink;
        }
        string getDessertName()
        {
            return desert;
        }
};

class pizzaBase
{
    private: 
        unordered_map<string,int> basePrice;
    public:
        pizzaBase()
        {
            basePrice.insert({"Regular",50});
            basePrice.insert({"Whole wheat",75});
        }
        int getBasePrice(string typeBase)
        {
            return basePrice[typeBase];
        }
};

// class sauce
// {

// };

class toppings
{
    private:
        unordered_map<string,int> toppingPrice;
    public:
        toppings()
        {
            toppingPrice.insert({"Mozzarella cheese",30});
            toppingPrice.insert({"Cheddar cheese",35});
            toppingPrice.insert({"Spinach",20});
            toppingPrice.insert({"Corn",15});
            toppingPrice.insert({"Mushroom",15});
            toppingPrice.insert({"Chicken",50});
            toppingPrice.insert({"Pepperoni",45});
        };
        int getToppingPrice(string typeTopping)
        {
            return toppingPrice[typeTopping];
        }
};

class drinkAndDesert
{
    private:
        unordered_map<string,int> drinksPrice;
        unordered_map<string,int> dessertPrice;
    public:
        drinkAndDesert()
        {
            drinksPrice.insert({"Pepsi",17});
            drinksPrice.insert({"7-up",19});
            drinksPrice.insert({"Coke",20});
            dessertPrice.insert({"Lava cake",95});
            dessertPrice.insert({"Chocolate brownie",86});
        }
        int getDrinksPrice(string typeDrink)
        {
            return drinksPrice[typeDrink];
        }
        int getDessertprice(string typeDesert)
        {
            return dessertPrice[typeDesert];
        }
};

class calculatePrice
{
    private:
        customer customerOrder;
        pizzaBase base;
        toppings toppingList;
        drinkAndDesert drinkAndDesertList;
    public:
        calculatePrice(customer customerOrder)
        {
            this->customerOrder=customerOrder;
            this->base=base;
            this->toppingList=toppingList;
            this->drinkAndDesertList=drinkAndDesertList;
        }

        // see customer details

        void showCustomerOrder()
        {
            customerOrder.customerOrderDetails();
        }

        bool isDiscountApplicable(string drink,string desert)
        {
            if(drink=="" || desert=="")
                return false;
            else
                return true;
        }

        void calculate()
        {
            double totalPrice=0;
            string baseName=customerOrder.getBaseName();
            vector<string> toppings=customerOrder.getToppingsList();
            string drink=customerOrder.getDrinkName();
            string desert=customerOrder.getDessertName();
            int basePrice=base.getBasePrice(baseName);
            int drinkPrice=drinkAndDesertList.getDrinksPrice(drink);
            int desertPrice=drinkAndDesertList.getDessertprice(desert);
            int toppingsPrice=0;
            string displayToppingPriceList="";
            double discount=0;
            for(auto i:toppings)
            {
                toppingsPrice+=toppingList.getToppingPrice(i);
                displayToppingPriceList+=to_string(toppingList.getToppingPrice(i))+" + ";
            }   
            totalPrice=basePrice+drinkPrice+desertPrice+toppingsPrice;
            if(isDiscountApplicable(drink,desert))
            {
                // cout<<"discount applied\n";
                discount=(totalPrice*0.05);
            }
            totalPrice-=discount;
            cout<<"Base Price : "<<basePrice<<"\n";
            cout<<"drink Price : "<<drinkPrice<<"\n";
            cout<<"desertPrice : "<<desertPrice<<"\n";
            cout<<"Toppings Price : "<<toppingsPrice<<"\n";
            cout<<"Discount : "<<discount<<"\n";
            cout<<"Amount to be paid : "<<totalPrice<<" Rs\n";
            // cout<<"[ Calculation : "<<basePrice<<" (base) + ("<<displayToppingPriceList.substr(0,displayToppingPriceList.length()-3)+")(topping) + "<<drinkPrice<<" + "<<desertPrice<<" - "<<discount<<"(discount) = "<<totalPrice<<"\n";
        }
};

int main()
{
    int testCase;
    cin>>testCase;
    while(testCase--)
    {
        // "Regular","Marinara sauce",{"Mozzarella cheese","Pepperoni"},"Coke","Lava cake"
        customer c1;
        c1.enterDetails();
        calculatePrice calculate(c1);
        calculate.showCustomerOrder();
        // calculate.calculate();
    }
}