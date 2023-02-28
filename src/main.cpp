#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>
#include <curl/curl.h>

//List of allowed file extensions.
//Add the file extensions you want to be able to read with <sitecat>. 
//To compile run "g++ -o sitecat src/main.cpp -lcurl".
const std::string allowedExtensions[] = {".txt", ".TXT", ".md", ".MD", 
".go", ".GO", ".js", ".JS", ".rust", ".RUST", ".css", ".CSS", ".c", ".C", ".cpp", ".CPP",
".json", ".JSON", ".config", ".CONFIG", "LICENSE", ".html", ".HTML", ".xml", ".XML"};

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cout << "Error! \n" << "To cat a file do: sitecat <url or file path>" << std::endl;
        return 1;
    }

    std::string fileUrl = argv[1];

    if (fileUrl.substr(0, 4) == "http") {
        //Download file from URL.
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
    } else {
        //Read file from local file path.
        std::ifstream file(fileUrl);
        if (file.is_open()) {
            std::cout << file.rdbuf();
            file.close();
        } else {
            std::cout << "Error: Failed to open file!" << std::endl;
            return 1;
        }
    }

    return 0;
}
