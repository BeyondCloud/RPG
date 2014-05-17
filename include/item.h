#ifndef BACKPACKITEM_H
#define BACKPACKITEM_H

#include <string>


class Item
{
    public:
        Item();
        Item(unsigned int);
        virtual ~Item();
        Item(const Item& other);
        Item& operator=(const Item& other);

        int useInBattle();
        int useOnMap();

        unsigned int getID() { return _id; };
        std::string getName() { return _name; };
        std::string getDescription() { return _description; };
        int getSalePrice() { return _price * 0.7; };
        int gerBuyPrice() { return _price; };

        bool isComsumable() { return _iscomsumable; };

        bool operator<(const Item&) const;
        bool operator<=(const Item&) const;
        bool operator>(const Item&) const;
        bool operator>=(const Item&) const;
        bool operator==(const Item&) const;
        bool operator!=(const Item&) const;

    protected:
    private:
        int use();

        unsigned int _id;
        std::string _name;
        std::string _description;
        int _price;
        bool _iscomsumable;
};

#endif // BACKPACKITEM_H
