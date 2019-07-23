class Animal():
    Nutrition = 'Carnivor'
    Desplacement = 'Walk'
    feet = 2

    def setNutrition(self, var):
        self.Nutrition = var

    def getNutrition(self):
        return self.Nutrition

myDog = Animal()
myDog.Nutrition = 'Herb'
myDog.feet = 3
print(myDog.getNutrition())
