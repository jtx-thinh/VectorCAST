#ifndef _TUTORIAL_TYPES_H_
#define _TUTORIAL_TYPES_H_ 


#define SEATS_AT_ONE_TABLE  4
#define NUMBER_OF_TABLES    6

#define COST_OF_STEAK   14
#define COST_OF_CHICKEN 10
#define COST_OF_LOBSTER 18
#define COST_OF_PASTA   12

enum boolean   { v_false, v_true };
enum soups     { NO_SOUP, ONION, CHOWDER };
enum salads    { NO_SALAD, CAESAR, GREEN };
enum entrees   { NO_ENTREE, STEAK, CHICKEN, LOBSTER, PASTA };
enum desserts  { NO_DESSERT, CAKE, PIE, FRUIT };
enum beverages { NO_BEVERAGE, WINE, BEER, MIXED_DRINK, SODA };

struct order_type
{
  enum soups     Soup;
  enum salads    Salad;
  enum entrees   Entree;
  enum desserts  Dessert;
  enum beverages Beverage;
};

typedef unsigned short seat_index_type;
typedef unsigned short table_index_type;

struct table_data_type
{
  enum boolean      Is_Occupied;
  seat_index_type   Number_In_Party;
  char              Designator;
  char              Wait_Person[10];
  struct order_type Order[SEATS_AT_ONE_TABLE];
  float             Check_Total;
};

typedef char name_type[32];


#endif /* _TUTORIAL_TYPES_H_ */
