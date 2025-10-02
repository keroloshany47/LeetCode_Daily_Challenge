class Solution {
public:
   int maxBottlesDrunk(int numBottles, int numExchange) {
       int total=numBottles;
       while(numBottles>=numExchange){
           total++;
           numBottles-=numExchange;
           numBottles++;
           numExchange++;
       }
       return total;
   }
};  
