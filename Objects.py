class Vehicle:
    """docstring for Vehicle."""
    make            = ''
    model           = ''
    year            = 0
    horsePower      = 0
    transmission    = ''

    def __init__(self, arg):
        self.arg = arg

    def setups(self):
        self.make = 'BMW'
        self.model = '3 serries'
        self.year = 2019
        self.horsePower = 360
        self.transmission = 'Automatic'

class Car(Vehicle):
    """docstring for Car."""
    mileage = '12,894'

    def characteristics(self):
        self.setups()
        print('******** Welcome to Nadhel\'s deals!!! *******')
        print('-+-+-+-+ NEW DEALS +-+-+-+')
        print('this is the brand new: ', self.make, self.model, self.year, 'with a horsePower of ',
        self.horsePower, self.transmission, 'transmission and', self.mileage, 'miles!')

BM = Car("BMW")
BM.characteristics()
