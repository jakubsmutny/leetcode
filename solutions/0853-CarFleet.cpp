class Car {
public:
    int position;
    int speed;
    Car(int p, int s) : position(p), speed(s) {}
    bool operator<(const Car &other) const {
        return position > other.position;
    }
};

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<Car> cars = vector<Car>();
        for(int i = 0; i < position.size(); ++i)
            cars.push_back(Car(position[i], speed[i]));
        sort(cars.begin(), cars.end());
        int fleets = cars.size();
        double latest = 0;
        for(int i = 0; i < cars.size(); ++i) {
            double arrive = (double)(target - cars[i].position) / cars[i].speed;
            // if arrive <= latest
            if(arrive - latest < DBL_EPSILON) --fleets;
            else latest = arrive;
        }
        return fleets;
    }
};
