# Load package
'''
If you install your package with:
    python3 setup.py install
Then you can simply call it like other installed packages, i.e.:
import mypkg

For test purposes, I run:
    python3 setup.py install --install-lib ./mypkg_installed

Then the package will be in the local folder.
'''
from mypkg_installed.mypkg import test

# You can see the available methods using
#print(help(test))

# Print directly using C++
test.printSomething()

# Retrieve some text from C++
print(test.getText())


# Send some values and print it
test.printTheseValues("My value passed from Python to C", 90)
