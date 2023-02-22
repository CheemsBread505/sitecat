# SiteCat

SiteCat is a simple command-line utility for viewing the contents of files either from a local file path or from a URL. It is a lightweight and flexible alternative to more complex tools, with a focus on simplicity and ease of use.

SiteCat is written in C++ and depends on the curl library for downloading files from URLs. It is open source and released under the GPL-3.0 license.

If you have any suggestions, feature requests, or bug reports, please feel free to open an issue or a pull request. I welcome your feedback and contributions!

## Dependencies

SiteCat depends on the `curl` library, which can be installed using your system's package manager.

On Ubuntu:

    sudo apt-get install libcurl4-openssl-dev
On arch:

    sudo pacman -S curl openssl

## Install

To install SiteCat, you will need to compile it first by running the following command in your terminal:

    git clone https://github.com/CheemsBread505/sitecat.git
    cd sitecat
    sudo make
    sudo cp sitecat /usr/bin/
## Usage
After you have successfully compiled the program, you can use it by running the following command:

    sitecat <url or file path>
For example, if you want to view the contents of a local file called `example.txt`, you can run the following command:

    sitecat example.txt
If you want to view the contents of a file from a URL, you can run the following command:

    sitecat https://example.com/example.txt
## Allowed file extensions

SiteCat has a list of allowed file extensions that it can read. These are the file extensions that are currently supported:

    .txt, .md, .go, .js, .rust, .css, .c, .cpp, .json, .config, .html

## License

SiteCat is released under the GNU General Public License v3.0; See the [LICENSE](https://github.com/CheemsBread505/sitecat/blob/main/LICENSE) file for more details.
