from BagTest import *
from BagTestExtended import *
from datetime import datetime

start = datetime.now()

# Run the set of tests from BagTest.py
testAll()
print("All Short Tests Passed.")

# Run the set of tests from BagTestExtended.py
testAllExtended()
print("All Extended Tests Passed.")

end = datetime.now()

diff = end - start
millis = diff.days * 24 * 60 * 60 * 1000
millis += diff.seconds * 1000
millis += diff.microseconds / 1000

print("Total runtime: " + str(millis) + "ms.")
