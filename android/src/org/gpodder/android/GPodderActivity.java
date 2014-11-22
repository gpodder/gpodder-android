package org.gpodder.android;

import org.qtproject.qt5.android.bindings.QtActivity;

import android.media.AudioManager;
import android.content.IntentFilter;


public class GPodderActivity extends QtActivity {
    @Override
    public void onResume() {
        IntentFilter filter = new IntentFilter(AudioManager.ACTION_AUDIO_BECOMING_NOISY);
        NoisyAudioStreamReceiver receiver = new NoisyAudioStreamReceiver();
        registerReceiver(receiver, filter);
        super.onResume();
    }
}
