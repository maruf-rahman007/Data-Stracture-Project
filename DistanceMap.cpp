#include <iostream>
#include <map>
#include <vector>

using namespace std;

vector<string>city_name = {"Dhaka","Sylhet","Khulna","Chittagong","Cumilla"};

// Function to display the distance map
void displayDistanceMap(const vector<vector<int>>& distanceMap)
{
    cout << "Distance Map:\n";
    cout << "------------\n";
    cout << "Cities:\t\tDhaka\t      Sylhet\t       Khulna\t    Chittagong\t      Cumilla\n";
    for (int i = 0; i < distanceMap.size(); ++i)
    {
        if(i == 0)
        {
            cout << city_name[i] << ":\t\t";
        }
        else
        {
            cout << city_name[i] << " "<< ":\t";
        }
        for (int j = 0; j < distanceMap[i].size(); ++j)
        {
            cout << distanceMap[i][j] << "\t\t";
        }
        cout << endl;
    }
}

// Function to add a historic place to a city
void addHistoricPlace(map<int, string>& historicPlaces, int city, const string& place)
{
    historicPlaces[city] += (historicPlaces[city].empty() ? "" : ", ") + place;
}

int main()
{
    // City indices: 0 = Dhaka, 1 = Sylhet, 2 = Khulna, 3 = Chittagong, 4 = Cumilla
    const int numCities = 5;

    // Create an adjacency matrix to represent the distance map
    vector<vector<int>> distanceMap(numCities, vector<int>(numCities, 0));

    // Create a map to store historic places for each city
    map<int, string> historicPlaces;

    // Set distances between cities
    distanceMap[0][1] = 241;   // Dhaka to Sylhet
    distanceMap[0][2] = 332;   // Dhaka to Khulna
    distanceMap[0][3] = 263;   // Dhaka to Chittagong
    distanceMap[0][4] = 85;    // Dhaka to Cumilla
    distanceMap[1][0] = 241;   // Sylhet to Dhaka
    distanceMap[1][2] = 392;   // Sylhet to Khulna
    distanceMap[1][3] = 324;   // Sylhet to Chittagong
    distanceMap[1][4] = 176;   // Sylhet to Cumilla
    distanceMap[2][0] = 332;   // Khulna to Dhaka
    distanceMap[2][1] = 392;   // Khulna to Sylhet
    distanceMap[2][3] = 364;   // Khulna to Chittagong
    distanceMap[2][4] = 415;   // Khulna to Cumilla
    distanceMap[3][0] = 263;   // Chittagong to Dhaka
    distanceMap[3][1] = 324;   // Chittagong to Sylhet
    distanceMap[3][2] = 364;   // Chittagong to Khulna
    distanceMap[3][4] = 296;   // Chittagong to Cumilla
    distanceMap[4][0] = 85;    // Cumilla to Dhaka
    distanceMap[4][1] = 176;   // Cumilla to Sylhet
    distanceMap[4][2] = 415;   // Cumilla to Khulna
    distanceMap[4][3] = 296;   // Cumilla to Chittagong

    // Add historic places for each city
    addHistoricPlace(historicPlaces, 0, "Lalbagh Fort, Ahsan Manzil");
    addHistoricPlace(historicPlaces, 1, "Shah Jalal Shrine, Ratargul Swamp Forest");
    addHistoricPlace(historicPlaces, 2, "Sundarbans, Shat Gambuj Mosque");
    addHistoricPlace(historicPlaces, 3, "Patenga Beach, Foy's Lake");
    addHistoricPlace(historicPlaces, 4, "Mainamati Archaeological Site, Shalban Vihara");

    // Display the distance map
    displayDistanceMap(distanceMap);

    // Display historic places for each city
    cout << "\nHistoric Places:\n";
    cout << "----------------\n";
    int k = 0;
    for (const auto& entry : historicPlaces)
    {
        cout << city_name[k] << ": " << entry.second << endl;
        k++;
    }
    return 0;
}
