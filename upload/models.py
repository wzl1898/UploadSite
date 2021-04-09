from django.db import models
from django.contrib.auth.models import User
# Create your models here.

class upload_record(models.Model):
    user = models.ForeignKey(User, on_delete = models.CASCADE)
    created_time = models.DateTimeField(auto_now_add=True)
    file_name = models.CharField(max_length=100)

    def __str__(self):
        return self.file_name