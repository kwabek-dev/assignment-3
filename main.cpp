#include <iostream>
#include <vector>
#include <limits>
#include "Queue.h"
#include "SearchSort.h"
using namespace std;

int main() {
    Queue<int> q;
    vector<int> vec = {1, 2, 3, 2, 4, 2, 5};
    int choice;

    while (true) {
        cout << "\n===== MAIN MENU =====\n";
        cout << "1. Push 10 integers into Queue\n";
        cout << "2. Display Queue\n";
        cout << "3. Move front element to rear\n";
        cout << "4. Recursive Linear Search (Last Occurrence)\n";
        cout << "5. Sort Queue (Insertion Sort)\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number.\n";
            continue;
        }

        switch (choice) {
        case 1:
            q.clear();                         // avoid repeated appends
            for (int i = 1; i <= 10; ++i) q.push(i);
            cout << "Queue reset and pushed integers 1..10.\n";
            break;
        case 2:
            cout << "Queue elements: ";
            q.display();
            break;
        case 3:
            q.move_to_rear();
            cout << "Moved front element to rear.\n";
            q.display();
            break;
        case 4: {
            cout << "Vector contents: ";
            for (int x : vec) cout << x << " ";
            cout << endl;
            int target;
            cout << "Enter target to find last occurrence: ";
            cin >> target;
            int pos = linear_search_last(vec, target, 0);
            if (pos == -1)
                cout << "Target not found.\n";
            else
                cout << "Last occurrence at index: " << pos << endl;
            break;
        }
        case 5:
            cout << "Queue before sorting: ";
            q.display();
            cout << "Sorting a copy of the queue (original preserved)...\n";
            {
                // Sort a copy so option 1/2 original order remains unchanged
                Queue<int> q_copy = q;
                insertion_sort_queue(q_copy); // sorts the copy
                cout << "Queue after sorting (sorted copy): ";
                q_copy.display();
            }
            break;
        case 6:
            cout << "Exiting...\n";
            return 0;
        default:
            cout << "Invalid choice.\n";
        }
    }
}
