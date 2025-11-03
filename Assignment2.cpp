#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Movie {
    string title;
    double imdbRating;
    int releaseYear;
    int watchTimePopularity;
};

void swap(Movie &a, Movie &b) {
    Movie temp = a;
    a = b;
    b = temp;
}

int partition(vector<Movie> &movies, int low, int high, string parameter) {
    Movie pivot = movies[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        bool condition = false;
        if (parameter == "rating") {
            if (movies[j].imdbRating >= pivot.imdbRating) condition = true;
        } else if (parameter == "year") {
            if (movies[j].releaseYear >= pivot.releaseYear) condition = true;
        } else if (parameter == "popularity") {
            if (movies[j].watchTimePopularity >= pivot.watchTimePopularity) condition = true;
        }

        if (condition) {
            i++;
            swap(movies[i], movies[j]);
        }
    }
    swap(movies[i + 1], movies[high]);
    return i + 1;
}

void quickSort(vector<Movie> &movies, int low, int high, string parameter) {
    if (low < high) {
        int pi = partition(movies, low, high, parameter);
        quickSort(movies, low, pi - 1, parameter);
        quickSort(movies, pi + 1, high, parameter);
    }
}

void printMovies(const vector<Movie> &movies) {
    for (auto &m : movies) {
        cout << m.title << "  Rating: " << m.imdbRating
             << "  Year: " << m.releaseYear
             << "  Popularity: " << m.watchTimePopularity << endl;
    }
}

int main() {
    vector<Movie> movies = {
        {"Avatar", 7.8, 2009, 92},
        {"The Matrix", 8.7, 1999, 94},
        {"Avengers: Endgame", 8.4, 2019, 97},
        {"Joker", 8.5, 2019, 89},
        {"Spider-Man: No Way Home", 8.3, 2021, 93}
    };

    string sortParameter;
    cin >> sortParameter;

    quickSort(movies, 0, movies.size() - 1, sortParameter);

    printMovies(movies);

    return 0;
}
