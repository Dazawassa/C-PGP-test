# Software needed
- [Visual Studio 2022](https://visualstudio.microsoft.com/thank-you-downloading-visual-studio/?sku=Community&channel=Release&version=VS2022&source=VSLandingPage&cid=2030&passive=false)
- MSVC compiler (Packaged with Visual Studio 2022)
- [PGPME](https://gpg4win.org/download.html)

# Setup PGPME
1. Open your project in Visual Studio 2022.
2. Right-click on your project in the Solution Explorer and select "Properties".
3. Navigate to the C/C++ section under Configuration Properties.
4. In the C/C++ section, click on "General".
5. In the right pane, find the "Additional Include Directories" property and add the path to your "Gpg4win\include" directory.
6. Next, navigate to the Linker section under Configuration Properties.
7. Under the Linker section, click on "General".
8. In the right pane, find the "Additional Library Directories" property and add the paths to your "Gpg4win\bin" and "Gpg4win\lib" directories.
9. Still under the Linker section, click on "Input".
10. In the right pane, find the "Additional Dependencies" property and add "libgpgme.imp".