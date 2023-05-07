from django.db import models

# Create your models here.

class Leitura(models.Model):
    created_at = models.DateTimeField(auto_now_add=True, )
    potencia = models.FloatField("Potência",)
