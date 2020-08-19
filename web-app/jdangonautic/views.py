from django.http import HttpResponse
from django.shortcuts import render
from time import time, sleep
from urllib.request import urlopen
from django.template import loader
import sys


def home(request):
    return render(request,'home.html')

def login(request):
    return render(request,'login.html')

def signup(request):
    return render(request,'signup.html')

def medbox(request):
    return render(request,'medbox.html')

def new_medicine(request):
    return render(request,'new_medicine.html')
def upload_pres(request):
    return render(request,'upload_pres.html')

def med_not_taken(request):
    return render(request,'med_not_taken.html')

def medicine_added(request):

    if request.method == "POST":
        name = request.POST['med_name']
        hour = request.POST['med_hour']
        minute = request.POST['med_min']
        compno = request.POST['med_comp']
        print(name)

        WRITE_API = "5E88DL24PBL8WOSN"
        BASE_URL = "https://api.thingspeak.com/update?api_key={}".format(WRITE_API)

        SensorPrevSec = 0
        SensorInterval = 2 # 2 seconds
        ThingSpeakPrevSec = 0
        ThingSpeakInterval = 18
        x = True

        name_list = list(name.upper())
        temp = []

        for letter in name_list:
            temp.append(ord(letter))
            print(letter)

        print(temp)

        strg = ''.join([str(elem) for elem in temp])
        print(strg)

        a = str(temp[0])+str(temp[1])+str(temp[2])+str(temp[3])

        b = str(temp[4])+ str(temp[5])+str(temp[6])

        print(a,b)

        try:
            while x==True:

                if time() - SensorPrevSec > SensorInterval:
                    SensorPrevSec = time()
                    print("Medicine = {:.20s}".format(strg))
                    print("Hour = {:.20s}".format(hour))
                    print("Minute = {:.20s}".format(minute))
                    print("Compartment No. = {:.20s}".format(compno))

                if time() - ThingSpeakPrevSec > ThingSpeakInterval:

                    ThingSpeakPrevSec = time()
                    thingspeakHttp_f1 = BASE_URL + "&field1={:.20s}".format(strg) +"&field2={:.20s}".format(b) + "&field3={:.3s}".format(hour) + "&field4={:.2s}".format(minute) + "&field5={:.2s}".format(compno)
                    print(thingspeakHttp_f1)
                    conn_name = urlopen(thingspeakHttp_f1)
                    print("Response: {}".format(conn_name.read()))
                    conn_name.close()

                    x=False
                    sleep(1)

        except KeyboardInterrupt:
            conn_name.close()

        context = {
            'name': name,
            'hour': hour,
            'minute' : minute,
            'compno' : compno,

            }

        template = loader.get_template('medicine_added.html')
        return HttpResponse(template.render(context, request))

    return render(request,'medicine_added.html')
