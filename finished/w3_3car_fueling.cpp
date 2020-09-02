#include <iostream>


int main() {
    int distance = 0;
    int mpt = 0;
    int num_stops = 0;

    std::cin >> distance;
    std::cin >> mpt;
    std::cin >> num_stops;

    int stop;
    int current_stop = 0;
    int left_in_tank= mpt;
    int total_stops = 0;
    bool arrived = false;

    //let's keep this simple...
    for (int i = 0; i<num_stops;i++) {
        //get the next stop's value from user
        std::cin >> stop;

        //if we can make it to this stop without using all our gas?
        if (stop < current_stop + left_in_tank) {
            //gas spent
            left_in_tank -= stop - current_stop;
            //current position
            current_stop = stop;
        }//can we just make it?
        else if (stop == current_stop + left_in_tank) {
            current_stop = stop;
            left_in_tank = mpt;
            total_stops++;
        }
        else {//we cannot make it on the gas we have left
            //is this stop too far to reach on a full tank?
            if (stop - current_stop > mpt) {
                total_stops = -1;
                break;
            }//no, then let's refill and travel
            else {
                left_in_tank = mpt - (stop - current_stop);
                total_stops++;
                current_stop = stop;
            }
        }
    }

    //final checks...
    //is the destination too far to reach with the gas left in the tank?
    if (distance > current_stop + left_in_tank) {
        //if it is, can we make it by refueling?
        if (distance > current_stop + mpt)
            total_stops = -1;
        else //if too far for what's in the tank we just add a stop
            total_stops++;
    }



//    bool arrived = false;
//    while(!arrived) {
//        //can we make it from the current stop?
//        if (stops[current_stop] + mpt >= distance)
//            arrived = true;
//        else {//no? then if we are on the last stop,
//            //we cannot make it. Also, if we can not make it
//            //to the next stop, we also cannot make it
//            if (current_stop == num_stops || stops[current_stop+1] - stops[current_stop] > mpt)
//                break;
//            else {//since we can make it the next stop, let's see
//                //how many stops we skip
//                int checkstop = current_stop + 1;//traversal
//                while (checkstop != num_stops && stops[checkstop+1] - stops[current_stop] <= mpt)
//                    checkstop++;
//                //now that we know how far ahead we can go...
//                if (checkstop == num_stops)
//                    arrived = true;
//                else {
//                    current_stop = checkstop;
//                    total_stops++;
//                }
//            }
//        }
//    }
//
//    if (arrived)
//        std::cout << total_stops << std::endl;
//    else
//        std::cout << -1 << std::endl;
    std::cout << total_stops << std::endl;

    return 0;
}
