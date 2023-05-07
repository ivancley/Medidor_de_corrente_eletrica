from rest_framework import generics
from .models import Leitura
from .serializers import LeituraSerializer

class LeituraList(generics.ListCreateAPIView):
    queryset = Leitura.objects.all()
    serializer_class = LeituraSerializer