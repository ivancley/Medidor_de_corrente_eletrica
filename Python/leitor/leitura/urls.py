from django.urls import path

from . import views as views 

urlpatterns = [
    path('', views.LeituraList.as_view(), name="leitura_list"),
]