from django.contrib import admin
from django.conf.urls import url , include
from django.urls import path
from . import views
urlpatterns = [
    url(r'^admin/', admin.site.urls),
    url(r'^$', views.home),
    url(r'^login$', views.login),
    url(r'^signup$', views.signup),
    url(r'^med_not_taken$', views.med_not_taken),
    path('medbox', views.medbox, name="medbox"),
    path('new_medicine',views.new_medicine,name="new_medicine"),
    path('upload_pres',views.upload_pres,name="upload_pres"),
    path('medicine_added',views.medicine_added,name="medicine_added"),

    url(r'^articles/', include('articles.urls')),
    #url(r'^medbox$', views.medbox),
]
