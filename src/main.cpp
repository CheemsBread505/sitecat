#include <iostream>
#include <string>
#include <algorithm>
#include <curl/curl.h>

//List of allowed file extensions.
//Add the file extensions you want to beable to read with <sitecat>. 
//To compile run "g++ -o sitecat src/main.cpp -lcurl".
const std::string allowedExtensions[] = {".txt", ".TXT", ".md", ".MD", 
".go", ".GO", ".js", ".JS", ".rust", ".RUST", ".css", ".CSS", ".c", ".C", ".cpp", ".CPP",
".json", ".JSON", ".config", ".CONFIG", "LICENSE", ".html", ".HTML"};

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cout << "Error! \n" << "To cat a file do: sitecat <url>" << std::endl;
        return 1;
    }

    std::string fileUrl = argv[1];

    CURL* curl;
    CURLcode res;

    curl = curl_easy_init();
    if (curl) {
        std::string fileExtension = fileUrl.substr(fileUrl.find_last_of("."));
        if (std::find(std::begin(allowedExtensions), std::end(allowedExtensions), fileExtension) == std::end(allowedExtensions)) {
            std::cout << "Error: File type not supported!" << std::endl;
            return 1;
        }
        curl_easy_setopt(curl, CURLOPT_URL, fileUrl.c_str());
        res = curl_easy_perform(curl);
        if (res != CURLE_OK) {
            std::cout << "Failed to download file: " << curl_easy_strerror(res) << std::endl;
        }
        curl_easy_cleanup(curl);
    }
    return 0;
}
